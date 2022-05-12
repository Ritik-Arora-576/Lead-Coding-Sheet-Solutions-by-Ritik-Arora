// TC: O(coins.size()*amount)
// SC: O(amount)
// 1-D DP approach

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> v(amount+1,INT_MAX);
        
        v[0]=0;
        
        for(int i=1;i<=amount;i++)
        {
            for(int coin:coins)
                if(i-coin>=0 and v[i-coin]!=INT_MAX) v[i]=min(v[i],v[i-coin]+1);
        }
        
        return v[amount]==INT_MAX?-1:v[amount];
    }
};