// Hashmap Solution
// TC: O(N)
// SC: O(N)

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n=adjacentPairs.size();
        vector<int> ans(n+1);
        unordered_map<int,vector<int>> m;
        
        for(auto data:adjacentPairs)
        {
            m[data[0]].push_back(data[1]);
            m[data[1]].push_back(data[0]);
        }
        
        bool count=false;
        
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second.size()==1)
            {
                if(!count)
                {
                    count=true;
                    ans[0]=it->first;
                }
                
                else ans[ans.size()-1]=it->first;
            }
        }
        
        for(int i=1;i<ans.size()-1;i++)
        {
            int data=ans[i-1];
            if(m[data].size()==1) ans[i]=m[data][0];
            else ans[i]=m[data][0]==ans[i-2]?m[data][1]:m[data][0];
        }
        
        return ans;
    }
};