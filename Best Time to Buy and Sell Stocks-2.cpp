// Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// TC: O(n)
// SC: O(1)

int maxProfit(vector<int>& prices) {
        int buy=0;
        int sell=0;
        
        for(int i=prices.size()-1;i>=0;i--)
        {
            int temp=buy;
            buy=max(buy,sell-prices[i]);
            sell=max(sell,temp+prices[i]);
        }
        
        return buy;
    }