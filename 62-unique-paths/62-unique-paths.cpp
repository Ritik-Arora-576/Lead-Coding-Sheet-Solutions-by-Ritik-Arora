// 1D DP Approach
// TC: O(n*m)
// SC: O(n)

#define mod 2000000000
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        
        for(int i=m-2;i>=0;i--)
            for(int j=n-2;j>=0;j--)
                dp[j]=(dp[j]%mod+dp[j+1]%mod)%mod;
        
        return dp[0];
    }
};