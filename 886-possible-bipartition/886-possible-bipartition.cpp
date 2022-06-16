// Check if graph bipartite or not
// It is used to check whether the graph can be divided into exactly 2 subgroups or not
// BFS Approach
// TC: O(N)
// SC: O(N)

class Solution {
    bool check(vector<int> &color,vector<vector<int>>& graph,int &s)
    {
        queue<int> q;
        q.push(s);
        color[s]=0;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(int data:graph[node])
            {
                if(color[data]==-1)
                {
                    q.push(data);
                    if(color[node]==1) color[data]=0;
                    else color[data]=1;
                }
                
                else if(color[data]==color[node]) return false;
            }
        }
        
        return true;
    }
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);
        for(auto data:dislikes)
        {
            graph[data[0]-1].push_back(data[1]-1);
            graph[data[1]-1].push_back(data[0]-1);
        }
        
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!check(color,graph,i)) return false;
            }
        }
        
        return true;
    }
};