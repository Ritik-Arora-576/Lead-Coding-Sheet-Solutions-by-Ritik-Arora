// TC: O(row*col)
// SC: O(row*col)

class Solution {
    class store{
        public:
        int row;
        int col;
        int dist;
        
        store(int row,int col,int dist)
        {
            this->row=row;
            this->col=col;
            this->dist=dist;
        }
    };
    
public:
    int maxDistance(vector<vector<int>>& grid) {
        int sum=0;
        int m=grid.size();
        int n=grid[0].size();
        
        for(auto data:grid) sum+=accumulate(data.begin(),data.end(),0);
        
        if(sum==0 or sum==m*n) return -1;
        
        queue<store> q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    store s(i,j,0);
                    q.push(s);
                }
            }
        }
        
        int ans=0;
        
        while(!q.empty())
        {
            int row=q.front().row;
            int col=q.front().col;
            int dist=q.front().dist;
            q.pop();
            ans=max(ans,dist);
            
            if(row+1<m and grid[row+1][col]==0)
            {
                grid[row+1][col]=1;
                store s(row+1,col,dist+1);
                q.push(s);
            }
            
            if(row-1>=0 and grid[row-1][col]==0)
            {
                grid[row-1][col]=1;
                store s(row-1,col,dist+1);
                q.push(s);
            }
            
            if(col+1<n and grid[row][col+1]==0)
            {
                grid[row][col+1]=1;
                store s(row,col+1,dist+1);
                q.push(s);
            }
            
            if(col-1>=0 and grid[row][col-1]==0)
            {
                grid[row][col-1]=1;
                store s(row,col-1,dist+1);
                q.push(s);
            }
        }
        
        return ans;
    }
};