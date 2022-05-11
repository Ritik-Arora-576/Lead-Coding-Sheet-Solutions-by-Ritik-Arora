// TC: O(N)
// SC: O(N)
// Unordered Set solution

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k==0)
        {
            unordered_map<int,int> m;
            int count=0;
            
            for(int data:nums)
            {
                m[data]++;
                if(m[data]==2) count++;
            }
            
            return count;
        }
        
        unordered_set<int> s;
        int count=0;
        
        for(int data:nums)
        {
            if(s.find(data)==s.end())
            {
                if(s.find(data-k)!=s.end()) count++;
                if(s.find(data+k)!=s.end()) count++;
                s.insert(data);
            }
        }
        
        return count;
    }
};