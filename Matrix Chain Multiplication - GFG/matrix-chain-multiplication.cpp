// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> v;
        for(int i=1;i<N;i++) v.push_back({arr[i-1],arr[i]});
        
        int dp[N-1][N-1];
        
        for(int i=0;i<N-1;i++) for(int j=0;j<N-1;j++) dp[i][j]=0;
        
        for(int j=1;j<N-1;j++)
        {
            for(int i=j-1;i>=0;i--)
            {
                dp[i][j]=INT_MAX;
                
                for(int k=j;k>i;k--)
                {
                    int a=v[i][0];
                    int b=v[k][0];
                    int c=v[j][1];
                    dp[i][j]=min(dp[i][j],(a*b*c)+dp[i][k-1]+dp[k][j]);
                }
            }
        }
        
        return dp[0][N-2];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends