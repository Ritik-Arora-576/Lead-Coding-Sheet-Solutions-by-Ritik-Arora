// TC: O(N)
// SC: O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        
        int a=nums[0];
        int b=max(nums[1],nums[0]);
        
        for(int i=2;i<nums.size();i++)
        {
            int temp=a;
            a=b;
            b=max(b,temp+nums[i]);
        }
        
        return b;
    }
};