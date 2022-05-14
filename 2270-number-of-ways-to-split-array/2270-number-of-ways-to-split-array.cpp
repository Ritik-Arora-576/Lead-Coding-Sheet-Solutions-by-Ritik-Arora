class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int right_sum=0;
        for(int data:nums) right_sum+=data;
        
        long long int left_sum=0;
        int ans=0;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            right_sum-=nums[i];
            left_sum+=nums[i];
            
            if(left_sum>=right_sum) ans++;
        }
        
        return ans;
    }
};