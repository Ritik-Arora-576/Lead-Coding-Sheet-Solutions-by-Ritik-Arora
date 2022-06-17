// DFS Approach
// TC: O(n)
// SC: O(n)

class Solution {
    void dfs(vector<vector<int>> &graph,vector<bool> &visited,int i)
    {
        visited[i]=true;
        for(auto data:graph[i]) if(!visited[data]) dfs(graph,visited,data);
    }
    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<vector<int>> graph(n);
        vector<bool> visited(n,false);
        
        for(auto data:connections)
        {
            graph[data[0]].push_back(data[1]);
            graph[data[1]].push_back(data[0]);
        }
        
        int ans=-1;
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(graph,visited,i);
                ans++;
            }
        }
        
        return ans;
    }
};