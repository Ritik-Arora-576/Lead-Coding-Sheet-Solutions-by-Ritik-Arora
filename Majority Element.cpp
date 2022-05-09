// Question Link: https://leetcode.com/problems/majority-element/
// TC: O(n)
// SC: O(1)

int majorityElement(vector<int>& nums) {
        int count=0;
        int ele=nums[0];
        
        for(int data:nums)
        {
            if(data==ele)
                count++;
            
            else count--;
            
            if(count==0)
            {
                ele=data;
                count=1;
            }
        }
        
        return ele;
    }