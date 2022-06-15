// TC: O(n*n*k)
// SC: O(n)

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        double dp[2][nums.size()+1];
        dp[0][nums.size()]=0.000000;
        dp[1][nums.size()]=0.000000;
        
        int sum=0;
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            sum+=nums[i];
            double avg=sum/((nums.size()-i)*1.000000);
            dp[0][i]=avg;
        }
        
        for(int t=2;t<=k;t++)
        {
            for(int i=nums.size()-1;i>=0;i--)
            {
                sum=0;
                for(int j=i;j<nums.size();j++)
                {
                    sum+=nums[j];
                    double avg=sum/((j-i+1)*1.000000);
                    dp[1][i]=max(dp[1][i],dp[0][j+1]+avg);
                }
            }
            
            for(int i=nums.size()-1;i>=0;i--)
            {
                dp[0][i]=dp[1][i];
                dp[1][i]=0.000000;
            }
        }
        
        return dp[0][0];
    }
};