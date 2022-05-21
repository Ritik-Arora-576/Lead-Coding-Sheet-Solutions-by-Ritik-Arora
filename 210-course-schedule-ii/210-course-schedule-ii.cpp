// Kahn's Algorithm

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> indegree(n,0);
        vector<vector<int>> graph;
        
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            graph.push_back(v);
        }
        
        for(auto data:prerequisites)
        {
            indegree[data[0]]++;
            graph[data[1]].push_back(data[0]);
        }
        
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int data=q.front();
            q.pop();
            
            ans.push_back(data);
            
            for(int data1:graph[data])
            {
                indegree[data1]--;
                if(indegree[data1]==0)
                    q.push(data1);
            }
        }
        
        if(ans.size()==n) return ans;
        
        return {};
    }
};