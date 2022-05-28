// TC: O(row*col)
// SC: O(1)

class Solution {
    void iterate(int i,int j,int &row,int &col,vector<vector<char>>& grid)
    {
        if(i<0 or j<0 or i==row or j==col or grid[i][j]=='0') return;
        
        grid[i][j]='0';
        
        iterate(i+1,j,row,col,grid);
        iterate(i-1,j,row,col,grid);
        iterate(i,j+1,row,col,grid);
        iterate(i,j-1,row,col,grid);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int row=grid.size();
        int col=grid[0].size();
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    iterate(i,j,row,col,grid);
                }
            }
        }
        
        return ans;
    }
};