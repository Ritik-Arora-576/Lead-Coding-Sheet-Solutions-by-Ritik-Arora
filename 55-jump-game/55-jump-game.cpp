// TC: O(N)
// SC: O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int canReach=n-1;
        
        for(int i=n-2;i>=0;i--)
            if(i+nums[i]>=canReach) canReach=i;
        
        return canReach==0;
    }
};