// 1D DP Approach
// TC: O(N^2)
// SC: O(N)

#define mod 2000000000
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        
        for(int i=m-2;i>=0;i--)
        {
            int temp=1;
            for(int j=n-2;j>=0;j--)
            {
                dp[j]=(dp[j]%mod+temp%mod)%mod;
                temp=dp[j];
            }
        }
        return dp[0];
    }
};