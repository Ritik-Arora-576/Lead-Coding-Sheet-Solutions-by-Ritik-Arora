// TC: O(N)
// SC: O(1)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int s=0;
        int e=1;
        int ans=0;
        int diff=INT_MAX;
        
        while(e<nums.size())
        {
            if(nums[e]-nums[e-1]!=diff)
            {
                diff=nums[e]-nums[e-1];
                int len=e-s;
                if(len>=3) ans+=((len*(len+1)/2)-len-(len-1));
                s=e-1;
            }
            
            e++;
        }
        
        
        int len=e-s;
        if(len>=3) ans+=((len*(len+1)/2)-len-(len-1));
        s=e-1;
        
        return ans;
    }
};