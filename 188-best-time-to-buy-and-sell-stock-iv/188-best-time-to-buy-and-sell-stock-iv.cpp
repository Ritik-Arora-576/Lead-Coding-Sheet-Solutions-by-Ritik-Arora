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
    // SC: O(k)
    
    int maxProfit(int k, vector<int>& prices) {
        int dp[2][k+1][2];
        
        for(int i=0;i<=k;i++)
        {
            dp[1][i][0]=0;
            dp[1][i][1]=0;
            dp[0][i][0]=0;
            dp[0][i][1]=0;
        }
        
        for(int i=prices.size()-1;i>=0;i--)
        {
            for(int j=1;j<=k;j++)
            {
                dp[0][j][0]=max(dp[1][j][1]-prices[i],dp[1][j][0]);
                dp[0][j][1]=max(dp[1][j-1][0]+prices[i],dp[1][j][1]);
            }
            
            for(int j=1;j<=k;j++)
            {
                dp[1][j][0]=dp[0][j][0];
                dp[1][j][1]=dp[0][j][1];
            }
        }
        
        return dp[0][k][0];
    }
};