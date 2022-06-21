// TC: O(nlogn)
// SC: O(1)

class Solution {
    bool possible(vector<int>& nums, int m,int &mid)
    {
        int i=0;
        int sum=0;
        
        while(i<nums.size())
        {
            if(m==0) return false;
            
            sum+=nums[i];
            if(sum>mid)
            {
                m--;
                sum=0;
            }
            
            else i++;
        }
        
        return true;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        int s=0;
        int e=accumulate(nums.begin(),nums.end(),0);
        int ans=e;
        
        while(e>=s)
        {
            int mid=(s+e)/2;
            if(possible(nums,m,mid))
            {
                ans=mid;
                e=mid-1;
            }
            
            else s=mid+1;
        }
        
        return ans;
    }
};