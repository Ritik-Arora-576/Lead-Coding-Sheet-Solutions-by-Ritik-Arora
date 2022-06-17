// TC: O(N)
// SC: O(N)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> v(n);
        
        for(auto data:times)
            v[data[0]-1].push_back(make_pair(data[1]-1,data[2]));
        
        vector<int> dist(n,INT_MAX);
        dist[k-1]=0;
        queue<pair<int,int>> q;
        
        q.push(make_pair(k-1,0));
        
        while(!q.empty())
        {
            int node=q.front().first;
            int len=q.front().second;
            q.pop();
            
            for(auto data:v[node])
            {
                if(dist[data.first]>len+data.second)
                {
                    dist[data.first]=len+data.second;
                    q.push(make_pair(data.first,dist[data.first]));
                }
            }
        }
        
        int ans=0;
        for(int data:dist) ans=max(ans,data);
        
        return ans==INT_MAX?-1:ans;
    }
};