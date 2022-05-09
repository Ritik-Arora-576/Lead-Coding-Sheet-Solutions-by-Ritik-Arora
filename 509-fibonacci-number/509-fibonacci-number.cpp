class Solution {
public:
    int fib(int n) {
        /*
            Space Complexity: O(1)
            Time Complexity: O(n)
        */
        
        if(n<2) return n;
        
        int a=0;
        int b=1;
        
        for(int i=2;i<=n;i++)
        {
            int temp=b;
            b+=a;
            a=temp;
        }
        
        return b;
    }
};