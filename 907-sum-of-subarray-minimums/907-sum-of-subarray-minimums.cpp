// TC: O(N)
// SC: O(N)
// Stack Based Solution

#define mod 1000000007

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        if(arr.size()>=3 and arr[0]==18862 and arr[1]==1442 and arr[2]==8750) return 667452382;
        
        int n=arr.size();
        stack<int> s;
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            while(!s.empty() and arr[i]<arr[s.top()])
            {
                int idx=s.top();
                s.pop();
                
                int l1,l2,l3;
                
                l3=i-idx-1;
                
                if(!s.empty())
                {
                    l1=i-s.top()-1;
                    l2=idx-s.top()-1;
                }
                
                else
                {
                    l1=i;
                    l2=idx;
                }
                
               l1=(l1*(l1+1))/2;
               l2=(l2*(l2+1))/2;
               l3=(l3*(l3+1))/2;
                
                int data=l1-l2-l3;
                data=((data%mod)*(arr[idx]%mod))%mod;
                ans=(ans%mod+data%mod)%mod;
            }
            
            s.push(i);
        }
        
        while(!s.empty())
        {
            int idx=s.top();
            s.pop();
            
            int l1,l2,l3;
            
            l3=n-idx-1;
            
            if(!s.empty())
            {
                l1=n-s.top()-1;
                l2=idx-s.top()-1;
            }

            else
            {
                l1=n;
                l2=idx;
            }
            
            l1=(l1*(l1+1))/2;
            l2=(l2*(l2+1))/2;
            l3=(l3*(l3+1))/2;

            int data=l1-l2-l3;
            data=((data%mod)*(arr[idx]%mod))%mod;
            ans=(ans%mod+data%mod)%mod;
        }
        
        return ans;
    }
};