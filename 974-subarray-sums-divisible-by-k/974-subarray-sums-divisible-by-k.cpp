// TC: O(N)
// SC: O(N)
// Hashmap Solution

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int count=0;
        int sum=0;
        m[0]++;
        
        for(int data:nums)
        {
            sum+=data;
            int temp=0;
            
            if(sum>=0) temp=sum%k;
            else
            {
                temp=-1*sum;
                temp%=k;
                temp=(k-temp)%k;
            }
            
            if(m.find(temp)!=m.end()) count+=m[temp];
            m[temp]++;
        }
        
        return count;
    }
};