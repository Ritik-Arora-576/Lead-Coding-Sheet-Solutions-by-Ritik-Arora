// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends

# define mod 1000000007
class Solution{
    long long solve(int &n,int &k,int i)
    {
        if(i==n) return 1;
        if(i>n) return 0;
        
        long long ans=0;
        
        if(i==0)
        {
            k--;
            ans=(ans%mod + solve(n,k,i+1)%mod)%mod;
            ans=(ans%mod + solve(n,k,i+2)%mod)%mod;
            ans=(ans%mod * (k+1))%mod;
        }
        
        else
        {
            ans=(ans%mod + solve(n,k,i+1)%mod)%mod;
            ans=(ans%mod + solve(n,k,i+2)%mod)%mod;
            ans=(ans%mod * k)%mod;
        }
        
        return ans;
    }
    
    public:
    long long countWays(int n, int k){
        vector<long long> dp(n+2,0);
        dp[n+1]=0;
        dp[n]=1;
        
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=(dp[i]%mod + dp[i+1]%mod)%mod;
            dp[i]=(dp[i]%mod + dp[i+2]%mod)%mod;
            
            if(i==0) dp[i]=(dp[i]%mod *k)%mod;
            else dp[i]=(dp[i]%mod *(k-1))%mod;
        }
        
        return dp[0];
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends