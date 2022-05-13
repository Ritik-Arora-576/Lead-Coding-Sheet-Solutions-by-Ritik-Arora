class Solution {
    // recursive approach
    int solve(int k,vector<int>& prices,bool buy,int i)
    {
        if(k==0 or i==prices.size()) return 0;
        if(buy) return max(solve(k,prices,false,i+1)-prices[i],solve(k,prices,buy,i+1));
        return max(solve(k-1,prices,true,i+1)+prices[i],solve(k,prices,buy,i+1));
    }
    
public:
    // 2D DP approach
    // TC: O(k*prices.size())
    // SC: O(k*prices.size())
    
    int maxProfit(int k, vector<int>& prices) {
        int dp[prices.size()+1][k+1][2];
        
        for(int i=0;i<=k;i++)
        {
            dp[prices.size()][i][0]=0;
            dp[prices.size()][i][1]=0;
        }
        
        for(int i=0;i<=prices.size();i++)
        {
            dp[i][0][0]=0;
            dp[i][0][1]=1;
        }
        
        for(int i=prices.size()-1;i>=0;i--)
        {
            for(int j=1;j<=k;j++)
            {
                dp[i][j][0]=max(dp[i+1][j][1]-prices[i],dp[i+1][j][0]);
                dp[i][j][1]=max(dp[i+1][j-1][0]+prices[i],dp[i+1][j][1]);
            }
        }
        
        return dp[0][k][0];
    }
};