class Solution {
    // recursive approach
    int solve(vector<int>& jobDifficulty, int d,int i)
    {
        if(i==jobDifficulty.size() and d==0) return 0;
        if(i==jobDifficulty.size() and d!=0) return 400000;
        
        int maxEle=0;
        int ans=INT_MAX;
        
        for(int k=i;k<jobDifficulty.size();k++)
        {
            maxEle=max(maxEle,jobDifficulty[k]);
            ans=min(ans,maxEle+solve(jobDifficulty,d-1,k+1));
        }
        
        return ans;
    }
    
public:
    // 2-D DP approach
    // TC: O(n*n*d)
    // SC: O(n*d)
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        int dp[d+1][n+1];
        
        dp[0][n]=0;
        
        for(int i=0;i<n;i++) dp[0][i]=-1;
        for(int i=1;i<=d;i++) dp[i][n]=-1;
        
        for(int i=1;i<=d;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                int maxEle=0;
                dp[i][j]=INT_MAX;
                for(int k=j;k<n;k++)
                {
                    maxEle=max(maxEle,jobDifficulty[k]);
                    if(dp[i-1][k+1]!=-1) dp[i][j]=min(dp[i][j],maxEle+dp[i-1][k+1]);
                }
                
                if(dp[i][j]==INT_MAX) dp[i][j]=-1;
            }
        }
        
        return dp[d][0];
    }
};