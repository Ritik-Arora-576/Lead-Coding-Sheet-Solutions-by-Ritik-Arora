// TC: O(N)
// SC: O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            // check if the value of element within the range of an array
            // If yes then check whether an element present at ith index is present at right position or not and also the element at nums[i]-1th index
            // If not then swap it with an element present at nums[i]-1th index 
            while(nums[i]>0 and nums[i]<=nums.size() and nums[i]!=i+1 and nums[nums[i]-1]!=nums[i])
                swap(nums[i],nums[nums[i]-1]);
        }
        cout<<(nums[0]!=0+1);
        
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=i+1) return i+1;
        
        return nums.size()+1;
    }
};