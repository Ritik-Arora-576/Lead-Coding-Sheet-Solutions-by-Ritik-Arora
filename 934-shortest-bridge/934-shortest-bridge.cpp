// BFS+DFS solution
// TC: O(row*col)
// SC: O(row*col)

class Solution {
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
    void dfs(vector<vector<int>>& grid, int &row,int &col,int i,int j,int &data)
    {
        if(i<0 or j<0 or i==row or j==col or grid[i][j]!=1) return;
        grid[i][j]=data;
        
        dfs(grid,row,col,i-1,j,data);
        dfs(grid,row,col,i+1,j,data);
        dfs(grid,row,col,i,j+1,data);
        dfs(grid,row,col,i,j-1,data);
    }
    
    class store{
        public:
        int i;
        int j;
        int dist;
        
        store(int i,int j,int dist)
        {
            this->i=i;
            this->j=j;
            this->dist=dist;
        }
    };
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int data=-1;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1){
                    dfs(grid,row,col,i,j,data);
                    data--;
                } 
                
                else if(grid[i][j]==0) grid[i][j]=INT_MAX;
            }
        }
        
        queue<store> q;
        int ans=INT_MAX;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==-1)
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
            
            for(int k=0;k<4;k++)
            {
                int i=temp.i+dx[k];
                int j=temp.j+dy[k];
                
                if(i>=0 and i<row and j>=0 and j<col)
                {
                    if(grid[i][j]==-2) ans=min(ans,temp.dist);
                    else if(grid[i][j]!=-1 and grid[i][j]>temp.dist+1)
                    {
                        grid[i][j]=temp.dist+1;
                        store s(i,j,temp.dist+1);
                        q.push(s);
                    }
                }
            }
        }
        
        return ans;
    }
};