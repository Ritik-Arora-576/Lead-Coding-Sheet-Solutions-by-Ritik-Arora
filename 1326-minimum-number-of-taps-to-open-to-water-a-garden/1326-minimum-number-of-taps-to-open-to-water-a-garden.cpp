// TC: O(n)
// SC: O(n)

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> arr(n+1,100000);
        
        for(int i=0;i<=n;i++)
        {
            int taps=100000;
            if(i-ranges[i]<=0) taps=1;
            else for(int j=i;j>=i-ranges[i];j--) taps=min(taps,arr[j]+1);
            
            for(int j=i;j<=min(n,i+ranges[i]);j++) arr[j]=min(arr[j],taps);
        }
        
        return arr[n]>=100000?-1:arr[n];
    }
};