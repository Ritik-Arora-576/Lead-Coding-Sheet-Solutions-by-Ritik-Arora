// Longest Common Substring kind solution
// TC: O(len(nums1)*len(nums2))
// SC: O(len(nums2))

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        
        vector<vector<int>> dp;
        vector<int> v(len2+1,0);
        dp.push_back(v);
        dp.push_back(v);
        int ans=0;
        
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[1][j]=dp[0][j-1]+1;
                    ans=max(ans,dp[1][j]);
                }
                
                else dp[1][j]=0;
            }
            
            for(int j=1;j<=len2;j++) dp[0][j]=dp[1][j];
        }
        
        return ans;
    }
};