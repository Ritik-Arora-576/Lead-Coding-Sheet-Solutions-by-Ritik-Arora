// TC: O(N)
// SC: O(N)
// Prefix Sum Map Approach

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int count=0;
        m[0]=1;
        int sum=0;
        
        for(int data:nums)
        {
            sum+=data;
            if(m.find(sum-k)!=m.end())
                count+=m[sum-k];
            
            m[sum]++;
        }
        
        return count;
    }
};
