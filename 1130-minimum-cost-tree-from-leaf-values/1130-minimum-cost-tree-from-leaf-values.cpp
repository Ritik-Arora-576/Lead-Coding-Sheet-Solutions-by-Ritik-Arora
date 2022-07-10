// TC: O(n^3)
// SC: O(n^2)
// Partial DP

class Solution {
    // recursive approach
    
    pair<int,int> solve(vector<int>& arr,int s,int e)
    {
        if(s==e) return make_pair(0,arr[s]);
        if(s>e) return make_pair(0,0);
        
        int ans=INT_MAX;
        int val=0;
        
        for(int i=s;i<=e;i++)
        {
            pair<int,int> left=solve(arr,s,i-1);
            pair<int,int> right=solve(arr,i+1,e);
            int data=left.first+right.first+min(arr[i]*left.second+max(arr[i],left.second)*right.second,arr[i]*right.second+max(arr[i],right.second)*left.second);
            ans=min(ans,data);
            val=max(arr[i],max(left.second,right.second));
        }
        
        return make_pair(ans,val);
    }
    
public:
    // DP approach
    
    int mctFromLeafValues(vector<int>& arr) {
        // return solve(arr,0,arr.size()-1).first;
        int n=arr.size();
        pair<int,int> dp[n][n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) dp[i][j]=make_pair(0,arr[i]);
                else dp[i][j]=make_pair(0,0);
            }
        }
        
        for(int j=1;j<n;j++)
        {
            for(int i=j-1;i>=0;i--)
            {
                int ans=INT_MAX;
                int val=0;
                
                for(int k=i;k<=j;k++)
                {
                    pair<int,int> left,right;
                    if(i>k-1) left=make_pair(0,0);
                    else left=dp[i][k-1];
                    if(k+1>j) right=make_pair(0,0);
                    else right=dp[k+1][j];
                    
                    int data=left.first+right.first+min(arr[k]*left.second+max(arr[k],left.second)*right.second,arr[k]*right.second+max(arr[k],right.second)*left.second);
            ans=min(ans,data);
            val=max(arr[k],max(left.second,right.second));
                }
                
                dp[i][j]=make_pair(ans,val);
            }
        }
        
        return dp[0][n-1].first;
    }
};