// TC: O(n*k)
// SC: O(n)

class Solution {
    // recursive statement 
    int solve(vector<int>& arr, int i, int &k)
    {
        int ans=0;
        int max_ele=0;
        
        for(int s=1;s<=k;s++)
        {
            if(i+s-1==arr.size()) break;
            max_ele=max(max_ele,arr[i+s-1]);
            ans=max(ans,(max_ele*s)+solve(arr,i+s,k));
        }
        
        return ans;
    }
    
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       vector<int> dp(arr.size()+1,0);
        
        for(int i=arr.size()-1;i>=0;i--)
        {
            int s=1;
            int max_ele=0;
            
            while(i+s-1<arr.size() and s<=k)
            {
                max_ele=max(max_ele,arr[i+s-1]);
                dp[i]=max(dp[i],(max_ele*s)+dp[i+s]);
                s++;
            }
        }
        
        return dp[0];
    }
};