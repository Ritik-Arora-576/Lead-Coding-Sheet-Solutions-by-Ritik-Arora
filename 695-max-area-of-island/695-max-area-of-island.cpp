// TC: O(N^2)
// DFS approach

class Solution {
    int findArea(vector<vector<int>>& grid, int i,int j,int &row,int &col)
    {
        if(i<0 or j<0 or i>=row or j>=col or grid[i][j]==0) return 0;
        grid[i][j]=0;
        
        return 1+findArea(grid,i-1,j,row,col)+findArea(grid,i+1,j,row,col)+findArea(grid,i,j-1,row,col)+findArea(grid,i,j+1,row,col);
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        int row=grid.size();
        int col=grid[0].size();
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                    maxArea=max(maxArea,findArea(grid,i,j,row,col));
            }
        }
        return maxArea;
    }
};