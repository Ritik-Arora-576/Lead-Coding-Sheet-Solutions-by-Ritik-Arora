// TC: O(logn)
// SC: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        
        while(e>=s)
        {
            int mid=(s+e)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) e=mid-1;
            else s=mid+1;
        }
        
        return -1;
    }
};