// TC: O(N^2)
// SC: O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int diff=INT_MAX;
        int ans=-1;
        
        for(int i=0;i<nums.size()-2;i++)
        {
            int j=i+1;
            int k=nums.size()-1;
            
            while(j<k)
            {
                if(diff>abs(target-nums[i]-nums[j]-nums[k]))
                {
                    diff=abs(target-nums[i]-nums[j]-nums[k]);
                    ans=nums[i]+nums[j]+nums[k];
                }
                
                if(nums[i]+nums[j]+nums[k]>=target) k--;
                
                else j++;
            }
        }
        
        return ans;
    }
};