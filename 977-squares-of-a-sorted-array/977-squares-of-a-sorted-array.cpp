// TC: O(N)
// SC: O(N)
// Merge Sorted arrays

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        vector<int> v(nums.size());
        int k=nums.size()-1;
        
        while(k>=0)
        {
            if(abs(nums[i])>=abs(nums[j])) v[k--]=nums[i++];
            else v[k--]=nums[j--];
            v[k+1]*=v[k+1];
        }
        
        return v;
    }
};