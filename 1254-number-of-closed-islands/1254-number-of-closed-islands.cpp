// TC: O(row*col)

class Solution {
    bool dfs(vector<vector<int>>& grid, int &row, int &col, int i, int j)
    {
        if(i<0 or j<0 or i==row or j==col) return false;
        if(grid[i][j]) return true;
        
        grid[i][j]=1;
        
        bool left=dfs(grid,row,col,i,j-1);
        bool right=dfs(grid,row,col,i,j+1);
        bool up=dfs(grid,row,col,i+1,j);
        bool down=dfs(grid,row,col,i-1,j);
        
        return (left and right and up and down);
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        int row=grid.size();
        int col=grid[0].size();
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(!grid[i][j])
                {
                    if(dfs(grid,row,col,i,j)) ans++;
                }
            }
        }
        
        return ans;
    }
};