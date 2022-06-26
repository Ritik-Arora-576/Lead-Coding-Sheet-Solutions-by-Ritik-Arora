// TC: O(nlogn)
// SC: O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto data:nums) m[data]++;
        set<pair<int,int>> s;
        
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(s.size()<k) s.insert(make_pair(it->second,it->first));
            else if(s.begin()->first<it->second)
            {
                s.erase(s.begin());
                s.insert(make_pair(it->second,it->first));
            }
        }
        
        vector<int> ans;
        
        while(!s.empty())
        {
            ans.push_back(s.begin()->second);
            s.erase(s.begin());
        }
        
        return ans;
    }
};