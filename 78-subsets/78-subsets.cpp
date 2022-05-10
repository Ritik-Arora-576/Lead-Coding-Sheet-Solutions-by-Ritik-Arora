// TC: O(2^n)
// SC: O(n^2)

class Solution {
    void storeSubset(vector<vector<int>> &ans,vector<int> &temp, int i, vector<int> &nums)
    {
        if(i==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        storeSubset(ans,temp,i+1,nums);
        temp.push_back(nums[i]);
        storeSubset(ans,temp,i+1,nums);
        temp.pop_back();
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        storeSubset(ans,temp,0,nums);
        return ans;
    }
};