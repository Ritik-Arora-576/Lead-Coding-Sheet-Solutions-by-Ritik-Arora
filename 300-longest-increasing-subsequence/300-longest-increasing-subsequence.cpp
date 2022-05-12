// TC: O(NlogN)
// SC: O(N)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        
        for(int data:nums)
        {
            if(v.size()==0) v.push_back(data);
            else
            {
                int idx=lower_bound(v.begin(),v.end(),data)-v.begin();
                if(idx==v.size()) v.push_back(data);
                else v[idx]=data;
            }
        }
        
        return v.size();
    }
};