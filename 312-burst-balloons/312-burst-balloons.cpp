// TC: O(N^3)
// SC: O(N^2)

class Solution {
    // recursive approach
    // consider last executed balloon only then make a recursive call
    int solve(int s,int e,vector<int> &nums)
    {
        int ans=0;
        
        for(int k=s;k<=e;k++)
            ans=max(ans,(nums[k]*nums[s-1]*nums[e+1])+solve(s,k-1,nums)+solve(k+1,e,nums));
        
        return ans;
    }
    
public:
    int maxCoins(vector<int>& nums) {
//         nums.insert(nums.begin(), 1);
//         nums.push_back(1);
        
//         return solve(1,nums.size()-2,nums);
        int n=nums.size();
        int dp[n][n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=0;
                if(i==j)
                {
                    int l=1;
                    int r=1;
                    if(i>0) l=nums[i-1];
                    if(i<nums.size()-1) r=nums[i+1];
                    dp[i][j]=l*r*nums[i];
                }
            }
        }
        
        for(int j=1;j<n;j++)
        {
            for(int i=j-1;i>=0;i--)
            {
                int l=1;
                int r=1;
                if(i>0) l=nums[i-1];
                if(j<nums.size()-1) r=nums[j+1];
                
                for(int k=i;k<=j;k++)
                {
                    int data=nums[k]*l*r;
                    if(k-1>=i) data+=dp[i][k-1];
                    if(k+1<=j) data+=dp[k+1][j];
                    dp[i][j]=max(dp[i][j],data);
                }
            }
        }
        
        return dp[0][n-1];
    }
};