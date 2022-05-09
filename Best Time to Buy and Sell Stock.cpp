/*
    Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    Time Complexity: O(n)
    Space Complexity: O(1)
*/

int maxProfit(vector<int>& prices) {
        int ans=0;
        int minPrice=prices[0];
        
        for(int i=1;i<prices.size();i++)
        {
            minPrice=min(minPrice,prices[i]);
            ans=max(ans,prices[i]-minPrice);
        }
        
        return ans;
    }