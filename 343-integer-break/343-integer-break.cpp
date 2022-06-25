// TC: O(N^2)
// SC: O(N)
// 1-D DP Approach

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        
        for(int i=3;i<=n;i++)
        {
            dp[i]=0;
            for(int j=i-1;j>=1;j--)
            {
                dp[i]=max(dp[i],dp[j]*dp[i-j]);
                dp[i]=max(dp[i],dp[j]*(i-j));
                dp[i]=max(dp[i],j*(i-j));
            }
        }
        
        return dp[n];
    }
};
