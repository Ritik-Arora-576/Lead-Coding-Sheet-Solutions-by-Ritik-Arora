// Sorting
// TC: O(NlogN)
// SC: O(1)

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=0;
        int b=0;
        int c=0;
        int prev=-1;
        int i=0;
        
        while(i<nums.size())
        {
            int data=nums[i];
            int freq=0;
            while(i<nums.size() and data==nums[i]) freq++,i++;
            
            if(c==0)
            {
                a=data*freq;
                b=a;
            }
            
            else if(c==1)
            {
                if(data-prev==1) b=max(data*freq,b);
                else b+=data*freq;
            }
            
            else
            {
                int temp=b;
                if(data-prev==1) b=max(b,a+data*freq);
                else b+=data*freq;
                a=temp;
            }
            
            c++;
            prev=data;
        }
        
        return b;
    }
};