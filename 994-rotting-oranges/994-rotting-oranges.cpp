// TC: O(m*n)
// SC: O(m*n)

class Solution {
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    
    class store{
        public:
        int i;
        int j;
        int time;
        
        store(int i,int j,int time)
        {
            this->i=i;
            this->j=j;
            this->time=time;
        }
    };
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<store> q;
        int ans=0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==2)
                {
                    store s(i,j,0);
                    q.push(s);
                }
            }
        }
        
        while(!q.empty())
        {
            store temp=q.front();
            q.pop();
            ans=max(ans,temp.time);
            
            for(int k=0;k<4;k++)
            {
                int i=temp.i+dx[k];
                int j=temp.j+dy[k];
                
                if(i>=0 and j>=0 and i<row and j<col and grid[i][j]==1)
                {
                    grid[i][j]=2;
                    store s(i,j,temp.time+1);
                    q.push(s);
                }
            }
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        
        return ans;
    }
};