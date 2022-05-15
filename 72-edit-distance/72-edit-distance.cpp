// 1D DP Approach
// TC: O(len1*len2)
// SC: O(len2)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.length();
        int len2=word2.length();
        int dp[2][len2+1];
        
        for(int i=0;i<=len2;i++)
        {
            dp[0][i]=i;
            if(i==0) dp[1][i]=1;
        }
        
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(word1[i-1]==word2[j-1]) dp[1][j]=dp[0][j-1];
                else dp[1][j]=min(dp[1][j-1],min(dp[0][j],dp[0][j-1]))+1;
            }
            
            for(int j=1;j<=len2;j++) dp[0][j]=dp[1][j];
            dp[0][0]++;
            dp[1][0]++;
        }
        
        return dp[0][len2];
    }
};