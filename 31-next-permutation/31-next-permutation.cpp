/* TC: O(n)
   SC: O(1) */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool flag=false;
        
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                flag=true;
                int j=i;
                
                while(j<nums.size() and nums[j]>nums[i-1])
                    j++;
                
                j--;
                
                swap(nums[j],nums[i-1]);
                
                int k=nums.size()-1;
                j=i;
                
                while(k>j)
                swap(nums[k--],nums[j++]);
                break;
            }
        }
        
        if(!flag)
        {
            int i=0;
            int j=nums.size()-1;
            while(j>i)
                swap(nums[j--],nums[i++]);
        }
    }
};