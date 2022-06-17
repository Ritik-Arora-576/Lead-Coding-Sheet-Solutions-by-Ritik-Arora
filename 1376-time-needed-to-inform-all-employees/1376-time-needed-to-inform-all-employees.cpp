// TC: O(N)
// SC: O(N)

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++)
        {
            if(i==headID) continue;
            graph[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>> q;
        q.push(make_pair(headID,informTime[headID]));
        int ans=0;
        
        while(!q.empty())
        {
            int node=q.front().first;
            int node_time=q.front().second;
            q.pop();
            ans=max(ans,node_time);
            
            for(auto data:graph[node])
                q.push(make_pair(data,node_time+informTime[data]));
        }
        
        return ans;
    }
};