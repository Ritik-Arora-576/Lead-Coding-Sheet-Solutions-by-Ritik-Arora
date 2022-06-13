// TC: O(n^3)
// SC: O(n^2)

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        pair<int,int> dp[n][n];
        
        for(int i=0;i<n;i++)
            dp[i][i]=make_pair(0,arr[i]);
        
        for(int j=1;j<n;j++)
        {
            for(int i=j-1;i>=0;i--)
            {
                dp[i][j]=make_pair(INT_MAX,INT_MIN);
                
                for(int k=j;k>i;k--)
                {
                    dp[i][j].first=min(dp[i][j].first,(dp[i][k-1].first+dp[k][j].first+(dp[i][k-1].second*dp[k][j].second)));
                    dp[i][j].second=max(dp[i][k-1].second,dp[k][j].second);
                }
            }
        }
        
        return dp[0][arr.size()-1].first;
    }
};