class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
        vector<int> v(col);
        
        for(int j=0;j<col;j++)
        {
            int ans=j;
            for(int i=0;i<row;i++)
            {
                if((grid[i][ans]==-1 and ans==0) or (grid[i][ans]==1 and ans==col-1) or (grid[i][ans]==-1 and grid[i][ans-1]==1) or (grid[i][ans]==1 and grid[i][ans+1]==-1))
                {
                    ans=-1;
                    break;
                }
                
                else if(grid[i][ans]==1 and grid[i][ans+1]==1) ans++;
                else ans--;
            }
            
            v[j]=ans;
        }
        
        return v;
    }
};