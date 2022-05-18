// Greedy Approach
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        int curr_reach=0;
        int max_reach=0;
        int jump=0;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            max_reach=max(max_reach,nums[i]+i);
            if(i==curr_reach)
            {
                jump++;
                curr_reach=max_reach;
            }
        }
        
        return jump;
    }
};