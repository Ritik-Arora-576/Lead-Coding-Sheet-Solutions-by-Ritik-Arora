// TC: O(N)
// SC: O(N)
// DFS approach

class Solution {
    bool dfs(vector<vector<int>> &graph,vector<bool> &visited,vector<int> &ans,vector<int> &temp,int &node,int src,int par)
    {
        visited[src]=true;
        temp.push_back(src);
        
        for(int data:graph[src])
        {
            if(!visited[data])
            {
                if(dfs(graph,visited,ans,temp,node,data,src)) return true;
            }
            
            else if(data!=par)
            {
                ans=temp;
                node=data;
                return true;
            }
        }
        
        temp.pop_back();
        return false;
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> graph(n);
        
        for(auto data:edges)
        {
            graph[data[0]-1].push_back(data[1]-1);
            graph[data[1]-1].push_back(data[0]-1);
        }
        
        vector<bool> visited(n,false);
        vector<int> ans;
        int node=-1;
        
        vector<int> temp;
        dfs(graph,visited,ans,temp,node,0,-1);
        
        for(int i=0;i<n;i++) visited[i]=false;
        
        int i=0;
        
        while(ans[i]!=node) i++;
        while(i<ans.size()) visited[ans[i++]]=true;
        
        for(int i=edges.size()-1;i>=0;i--)
        {
            int a=edges[i][0]-1;
            int b=edges[i][1]-1;
            if(visited[a] and visited[b]) return edges[i];
        }
        
        return ans;
    }
};