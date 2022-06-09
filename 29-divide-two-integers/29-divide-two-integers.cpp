// TC: O(logn)
// SC: O(1)

#define ll long long

class Solution {
public:
    int divide(int dividend, int divisor) {
        ll a=dividend;
        ll b=divisor;
        bool status=false;
        
        if((a>=0 and b<0) or (a<=0 and b>0)) status=true;
        
        a=abs(a);
        b=abs(b);
        
        ll s=0;
        ll e=a;
        ll ans=s;
        
        while(e>=s)
        {
            ll mid=(e+s)/2;
            if(mid*b<=a)
            {
                ans=mid;
                s=mid+1;
            }
            
            else e=mid-1;
        }
        
        if(status) ans*=-1;
        
        if(ans>INT_MAX) ans=INT_MAX;
        if(ans<INT_MIN) ans=INT_MIN;
        
        return int(ans);
    }
};