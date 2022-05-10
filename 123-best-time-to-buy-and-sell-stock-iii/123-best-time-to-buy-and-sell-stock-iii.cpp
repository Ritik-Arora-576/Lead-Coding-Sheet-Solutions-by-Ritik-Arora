// TC: O(N)
// SC: O(N)
// 1-D DP approach

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp;
        int n=prices.size();
        dp.push_back(0);
        int minPrice=prices[0];
        
        for(int i=1;i<n;i++)
        {
            minPrice=min(minPrice,prices[i]);
            dp.push_back(max(dp[i-1],prices[i]-minPrice));
        }
        
        int maxPrice=prices[n-1];
        int ans=dp[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            maxPrice=max(maxPrice,prices[i]);
            ans=max(ans,dp[i]+(maxPrice-prices[i]));
        }
        
        return ans;
    }
};