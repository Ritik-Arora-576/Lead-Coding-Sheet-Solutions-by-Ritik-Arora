// TC: O(N)
// SC: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit1=0;
        int minPrice1=INT_MAX;
        int profit2=0;
        int minPrice2=INT_MAX;
        
        for(int data:prices)
        {
            minPrice1=min(minPrice1,data);
            profit1=max(profit1,data-minPrice1);
            
            // effective Price that the trader should pay after earning the profit from one transaction
            minPrice2=min(minPrice2,data-profit1);
            profit2=max(profit2,data-minPrice2);
        }
        
        return profit2;
    }
};