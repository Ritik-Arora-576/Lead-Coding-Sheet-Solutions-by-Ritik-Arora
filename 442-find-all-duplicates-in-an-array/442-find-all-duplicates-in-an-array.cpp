// TC: O(N)
// SC: Constant

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        for(int data:nums)
        {
            if(nums[abs(data)-1]<0) ans.push_back(abs(data));
            else nums[abs(data)-1]*=-1;
        }
        
        return ans;
    }
};