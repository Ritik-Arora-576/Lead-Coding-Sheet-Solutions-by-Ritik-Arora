// TC: O(N)
// SC: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int temp=1;
        int maxPos=1;
        int maxNeg=INT_MIN;
        
        for(int data:nums)
        {
            temp*=data;
            if(temp>0)
            {
                ans=max(ans,temp);
                maxPos=max(temp,maxPos);
            }
            
            else if(temp==0)
            {
                ans=max(ans,temp);
                maxPos=1;
                temp=1;
                maxNeg=INT_MIN;
            }
            
            else
            {
                if(temp>maxNeg)
                {
                    maxNeg=temp;
                    ans=max(ans,temp/maxPos);
                }
                
                else ans=max(ans,temp/maxNeg);
            }
        }
        
        return ans;
    }
};