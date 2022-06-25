// TC: O(logn)
// SC: O(logn)

class Solution {
    double solve(double &x,int n)
    {
        if(n==0) return 1.00000;
        if(n==1) return x;
        
        if(n%2) return x*solve(x,n-1);
        double data=solve(x,n/2);
        return data*data;
    }
    
public:
    double myPow(double x, int n) {
        bool status=false;
        if(n<0) status=true;
        int data=1.00000;
        if(n==INT_MIN)
        {
            n++;
            data=x;
        }
        n=abs(n);
        double ans=solve(x,n)*data;
        if(status) ans=1.00000/ans;
        return ans;
    }
};