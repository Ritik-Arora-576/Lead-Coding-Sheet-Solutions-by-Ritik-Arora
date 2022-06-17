// TC: O(n^2)
// SC: O(n)

class Solution {
public:
    int twoEggDrop(int n) {
        int dp[2][n+1];
        
        for(int i=0;i<=n;i++) dp[0][i]=i;
        dp[1][0]=0;
        dp[1][1]=1;
        
        for(int i=2;i<=n;i++)
        {
            dp[1][i]=INT_MAX;
            for(int k=1;k<=i;k++)
                dp[1][i]=min(dp[1][i],max(dp[0][k-1],dp[1][i-k])+1);
        }
        
        return dp[1][n];
    }
};