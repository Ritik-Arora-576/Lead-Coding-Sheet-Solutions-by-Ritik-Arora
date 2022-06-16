// BFS approach
// TC: O(n)

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n,false);
        visited[0]=true;
        
        queue<int> q;
        q.push(0);
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(int data:rooms[node])
            {
                if(!visited[data])
                {
                    q.push(data);
                    visited[data]=true;
                }
            }
        }
        
        for(int i=0;i<n;i++) if(!visited[i]) return false;
        
        return true;
    }
};