// TC: O(N)
// SC: O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count=0;
        for(int data:nums) if(data==0) count++;
        
        if(count>1)
        {
            for(int i=0;i<nums.size();i++) nums[i]=0;
            return nums;
        }
        
        int prod=1;
        for(int data:nums) if(data!=0) prod*=data;
        
        if(count==1)
        {
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==0) nums[i]=prod;
                else nums[i]=0;
            }
            
            return nums;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) nums[i]=prod;
            else nums[i]=prod/nums[i];
        }
        
        return nums;
    }
};