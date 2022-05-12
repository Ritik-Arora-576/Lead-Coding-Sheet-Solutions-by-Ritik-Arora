// TC: O(N)
// SC: O(K)
// Hashmap solution

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long int sum=0;
        unordered_map<int,int> m;
        m[0]=-1;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            
            if(m.find(sum%k)==m.end()) m[sum%k]=i;
            else if(i-m[sum%k]>=2) return true;
        }
        
        return false;
    }
};