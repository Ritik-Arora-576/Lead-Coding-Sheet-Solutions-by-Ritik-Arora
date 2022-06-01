class TimeMap {
    unordered_map<string,vector<pair<string,int>>> m;
    
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back(make_pair(value,timestamp));
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end() or m[key][0].second>timestamp) return "";
        int s=0;
        int e=m[key].size()-1;
        int idx=0;
        
        while(e>=s)
        {
            int mid=(e+s)/2;
            if(m[key][mid].second>timestamp) e=mid-1;
            else
            {
                s=mid+1;
                idx=mid;
            }
        }
        
        return m[key][idx].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */