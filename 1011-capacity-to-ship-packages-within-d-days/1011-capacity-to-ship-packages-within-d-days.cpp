// TC: O(nlogn)
// SC: O(1)

class Solution {
    bool isPossible(vector<int>& weights, int days,int &mid)
    {
        int sum=0;
        int i=0;
        
        while(i<weights.size())
        {
            if(days==0) return false;
            
            sum+=weights[i];
            
            if(sum>mid)
            {
                sum=0;
                days--;
                continue;
            }
            
            i++;
        }
        
        return true;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int e=accumulate(weights.begin(),weights.end(),0);
        int s=*max_element(weights.begin(), weights.end());
        int ans=e;
        
        while(e>=s)
        {
            int mid=(e+s)/2;
            
            if(isPossible(weights,days,mid))
            {
                ans=mid;
                e=mid-1;
            }
            
            else s=mid+1;
        }
        
        return ans;
    }
};