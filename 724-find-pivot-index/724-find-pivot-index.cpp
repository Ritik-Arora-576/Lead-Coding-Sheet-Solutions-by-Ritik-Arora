// TC: O(N)
// SC: O(1)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int leftsum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(leftsum==sum-nums[i])
                return i;
            
            leftsum+=nums[i];
            sum-=nums[i];
        }
        
        return -1;
    }
};