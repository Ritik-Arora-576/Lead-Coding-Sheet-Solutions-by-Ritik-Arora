// TC: O(N)
// SC: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int data:nums)
        {
            if(nums[abs(data)-1]<0) return abs(data);
            else nums[abs(data)-1]*=-1;
        }
        return -1;
    }
};