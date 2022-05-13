// Kadane's Algo in 2D
// TC: O(N^2)
// SC: O(N^2)

class NumMatrix {
    virtual void convert(vector<vector<int>> &dp)
    {
        int row=dp.size();
        int col=dp[0].size();
        
        for(int i=1;i<row;i++) for(int j=0;j<col;j++) dp[i][j]+=dp[i-1][j];
        for(int j=1;j<col;j++) for(int i=0;i<row;i++) dp[i][j]+=dp[i][j-1];
    }

    vector<vector<int>> v;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        convert(matrix);
        this->v=matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=v[row2][col2];
        
        if(row1>0) ans-=v[row1-1][col2];
        if(col1>0) ans-=v[row2][col1-1];
        if(row1>0 and col1>0) ans+=v[row1-1][col1-1];
        
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */