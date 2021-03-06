// TC: O(N)
// SC: O(1)

class Solution {
public:
    int kthFactor(int n, int k) {
        int num=0;
        
        for(int i=1;i<=n;i++)
        {
            if(n%i==0) num++;
            if(num==k) return i;
        }
        
        return -1;
    }
};