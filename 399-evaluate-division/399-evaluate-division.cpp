// TC: O(q*e)
// SC: O(e)

class Solution {
    bool dfs(unordered_map<string,vector<pair<string,double>>> &m,unordered_set<string> &s,double &ans,string &src,string &dest,double temp)
    {
        if(src==dest)
        {
            ans=temp;
            return true;
        }
        s.insert(src);
        
        for(auto data:m[src])
        {
            if(s.find(data.first)==s.end())
            {
                if(dfs(m,s,ans,data.first,dest,temp*data.second)) return true;
            }
        }
        
        s.erase(src);
        return false;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> m;
        vector<double> v;
        
        for(int i=0;i<equations.size();i++)
        {
            m[equations[i][0]].push_back(make_pair(equations[i][1],values[i]*1.00000));
            m[equations[i][1]].push_back(make_pair(equations[i][0],1.00000/values[i]));
        }
        
        for(auto data:queries)
        {
            if(m.find(data[0])==m.end() or m.find(data[1])==m.end()) 
            {
                v.push_back(-1.00000);
                continue;
            }
            
            unordered_set<string> s;
            double ans=-1.00000;
            dfs(m,s,ans,data[0],data[1],1.00000);
            v.push_back(ans);
        }
        
        return v;
    }
};