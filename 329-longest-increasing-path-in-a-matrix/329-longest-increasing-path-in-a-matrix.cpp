// DFS Approach
// TC: O(N*M)
// SC: O(N*M)

class Solution {
    int dfs(vector<vector<int>>& matrix,int &row,int &col,int i,int j,vector<vector<int>> &v,int prev)
    {
        if(i<0 or j<0 or i==row or j==col or prev>=matrix[i][j]) return 0;
        if(v[i][j]!=-1) return v[i][j];
        v[i][j]=max({dfs(matrix,row,col,i-1,j,v,matrix[i][j]),dfs(matrix,row,col,i+1,j,v,matrix[i][j]),dfs(matrix,row,col,i,j-1,v,matrix[i][j]),dfs(matrix,row,col,i,j+1,v,matrix[i][j])})+1;
        return v[i][j];
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> v(row,vector<int> (col,-1));
        int ans=0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(v[i][j]==-1)
                {
                    dfs(matrix,row,col,i,j,v,INT_MIN);
                    ans=max(ans,v[i][j]);
                }
            }
        }
        
        return ans;
    }
};