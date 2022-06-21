// Best TC: O(n+log(m))
// Worst TC: O(nlog(m))
// SC: O(1)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int final_ans=0;
        int last_idx=col;
        
        for(int i=0;i<row;i++)
        {
            int s=0;
            int e=last_idx-1;
            int ans=last_idx;
            
            while(e>=s)
            {
                int mid=(e+s)/2;
                if(grid[i][mid]<0)
                {
                    ans=mid;
                    e=mid-1;
                }
                
                else s=mid+1;
            }
            
            final_ans+=(col-ans);
            last_idx=ans;
        }
        
        return final_ans;
    }
};