// TC: O(N)
// SC: O(1)
// Kadane's Algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int sum=0;
        
        for(int data:nums)
        {
            sum+=data;
            ans=max(ans,sum);
            
            if(sum<0) sum=0;
        }
        
        return ans;
    }
};