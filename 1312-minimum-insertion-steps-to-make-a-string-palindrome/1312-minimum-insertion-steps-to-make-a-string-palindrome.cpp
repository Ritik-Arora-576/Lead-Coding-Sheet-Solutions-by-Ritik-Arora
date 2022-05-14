// string reversal + LCS
// TC: O(len1*len2)
// SC: O(len2)

class Solution {
    int lcs(string &str1,string &str2)
    {
        int len1=str1.length();
        int len2=str2.length();
        int dp[2][len2+1];
        
        for(int j=0;j<=len2;j++)
        {
            dp[0][j]=0;
            dp[1][j]=0;
        }
        
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(str1[i-1]==str2[j-1]) dp[1][j]=dp[0][j-1]+1;
                else dp[1][j]=max(dp[1][j-1],dp[0][j]);
            }
            
            for(int j=1;j<=len2;j++) dp[0][j]=dp[1][j];
        }
        
        return dp[1][len2];
    }
public:
    int minInsertions(string s) {
        string str1=s;
        reverse(s.begin(),s.end());
        return str1.length()-lcs(str1,s);
    }
};