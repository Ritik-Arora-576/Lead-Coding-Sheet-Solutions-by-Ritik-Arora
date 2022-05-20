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
    // SC: O(n)
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        int dp[2][n+1];
        
        dp[0][n]=0;
        dp[1][n]=-1;
        
        for(int i=0;i<n;i++) dp[0][i]=-1;
        
        for(int i=1;i<=d;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                int maxEle=0;
                dp[1][j]=INT_MAX;
                for(int k=j;k<n;k++)
                {
                    maxEle=max(maxEle,jobDifficulty[k]);
                    if(dp[0][k+1]!=-1) dp[1][j]=min(dp[1][j],maxEle+dp[0][k+1]);
                }
                
                if(dp[1][j]==INT_MAX) dp[1][j]=-1;
            }
            
            for(int j=0;j<=n;j++) dp[0][j]=dp[1][j];
        }
        
        return dp[1][0];
    }
};