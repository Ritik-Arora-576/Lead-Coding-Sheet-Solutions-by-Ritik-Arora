// TC: O(N)
// SC: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        for(int data:nums) if(data!=0) nums[i++]=data;
        while(i<nums.size()) nums[i++]=0;
    }
};