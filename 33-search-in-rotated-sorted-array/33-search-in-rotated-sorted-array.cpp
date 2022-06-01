// TC: O(logn)
// SC: O(1)

class Solution {
    int find(int s,int e,int &target,vector<int>& nums)
    {
        while(e>=s)
        {
            int mid=(e+s)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) e=mid-1;
            else s=mid+1;
        }
        
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int idx=e;
        
        while(e>=s)
        {
            int mid=(e+s)/2;
            
            if(nums[mid]>nums[nums.size()-1]) s=mid+1;
            else
            {
                idx=mid;
                e=mid-1;
            }
        }
        
        if(target>=nums[idx] and target<=nums[nums.size()-1]) return find(idx,nums.size()-1,target,nums);
        
        if(idx!=0 and target>=nums[0] and target<=nums[idx-1]) return find(0,idx-1,target,nums);
        
        return -1;
    }
};