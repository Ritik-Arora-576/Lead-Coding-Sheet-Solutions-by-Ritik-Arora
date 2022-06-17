// TC: O(N^2)
// SC: O(N)

class Solution {
    void dfs(vector<vector<pair<int,int>>> &graph,vector<int> &dist,int src)
    {
        queue<pair<int,int>> q;
        q.push(make_pair(dist[src],src));
        
        while(!q.empty())
        {
            int len=q.front().first;
            int node=q.front().second;
            q.pop();
            
            for(auto data:graph[node])
            {
                if(dist[data.first]>len+data.second)
                {
                    dist[data.first]=len+data.second;
                    q.push(make_pair(dist[data.first],data.first));
                }
            }
        }
    }
    
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int n_city=INT_MAX;
        int ans=-1;
        
        vector<vector<pair<int,int>>> graph(n);
        for(auto data:edges)
        {
            graph[data[0]].push_back(make_pair(data[1],data[2]));
            graph[data[1]].push_back(make_pair(data[0],data[2]));
        }
        
        for(int i=0;i<n;i++)
        {
            vector<int> dist(n,INT_MAX);
            dist[i]=0;
            dfs(graph,dist,i);
            
            int count=0;
            for(int data:dist) if(data<=distanceThreshold) count++;
            
            if(count<=n_city)
            {
                n_city=count;
                ans=i;
            }
        }
        
        return ans;
    }
};