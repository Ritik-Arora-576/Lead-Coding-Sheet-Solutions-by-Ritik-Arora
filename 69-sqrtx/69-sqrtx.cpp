// TC: O(logn)
// SC: O(1)

class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        int e=x;
        int ans=s;
        
        while(e>=s)
        {
            long long mid=(s+e)/2;
            
            if(mid*mid>x) e=mid-1;
            else
            {
                ans=mid;
                s=mid+1;
            }
        }
        
        return ans;
    }
};