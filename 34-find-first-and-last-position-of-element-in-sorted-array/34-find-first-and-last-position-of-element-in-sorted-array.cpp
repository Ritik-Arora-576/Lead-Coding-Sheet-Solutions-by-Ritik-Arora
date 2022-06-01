// TC: O(logn)
// SC: O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=-1;
        int end=-1;
        
        int s=0;
        int e=nums.size()-1;
        
        while(e>=s)
        {
            int mid=(e+s)/2;
            if(nums[mid]==target)
            {
                start=mid;
                e=mid-1;
            }
            
            else if(nums[mid]>target) e=mid-1;
            else s=mid+1;
        }
        
        s=0;
        e=nums.size()-1;
        
        while(e>=s)
        {
            int mid=(e+s)/2;
            if(nums[mid]==target)
            {
                end=mid;
                s=mid+1;
            }
            
            else if(nums[mid]>target) e=mid-1;
            else s=mid+1;
        }
        
        return {start,end};
    }
};