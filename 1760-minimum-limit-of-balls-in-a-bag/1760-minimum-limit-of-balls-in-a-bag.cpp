// TC: O(nlogn)
// SC: O(1)

class Solution {
    static bool compare(int &a,int &b) {return a>b;}
    
    bool check(vector<int>& nums, int maxOperations,int &mid)
    {
        for(int data:nums)
        {
            if(data<=mid) break;
            
            if(data%mid==0) maxOperations-=(data/mid)-1;
            else maxOperations-=(data/mid);
            
            if(maxOperations<0) return false;
        }
        
        return true;
    }
    
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(nums.begin(),nums.end(),compare);
        int s=1;
        int e=nums[0];
        int ans=e;
        
        while(s<=e)
        {
            int mid=(s+e)/2;
            
            if(check(nums,maxOperations,mid))
            {
                ans=mid;
                e=mid-1;
            }
            
            else s=mid+1;
        }
        
        return ans;
    }
};