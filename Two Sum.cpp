/*
    Question Link: https://leetcode.com/problems/two-sum/
    Hashmap Solution
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            
            m[nums[i]]=i;
        }
        
        return ans;
    }