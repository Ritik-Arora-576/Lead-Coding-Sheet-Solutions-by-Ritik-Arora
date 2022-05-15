class Solution {
    // recursive approach
    int solve(int l,int r,vector<int> &cuts)
    {
        int ans=INT_MAX;
        for(int cut:cuts)
            if(cut>l and cut<r) ans=min(ans,(r-l)+solve(l,cut,cuts)+solve(cut,r,cuts));
        
        return ans==INT_MAX?0:ans;
    }
public:
    // 2D DP approach
    // TC: O(cuts.size()^3)
    // SC: O(cuts.size()^2)
    
    int minCost(int k, vector<int>& cuts) {
        cuts.push_back(k);
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(), 0);
        int n=cuts.size();
        int dp[n][n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j-i<=1) dp[i][j]=0;
                else dp[i][j]=INT_MAX;
            }
        }
        
        for(int j=2;j<n;j++)
        {
            for(int i=j-2;i>=0;i--)
            {
                int len=cuts[j]-cuts[i];
                for(int k=j-1;k>i;k--)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+len);
            }
        }
        
        return dp[0][n-1];
    }
};