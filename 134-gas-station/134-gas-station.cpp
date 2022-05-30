// TC: O(n)
// SC: O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cap=0;
        int idx=0;
        int n=cost.size();
        
        for(int i=0;i<n;i++)
        {
            cap+=gas[i];
            cap-=cost[i];
            
            if(cap<0)
            {
                cap=0;
                idx=i+1;
            }
        }
        
        if(idx==n) return -1;
        
        for(int i=0;i<=idx;i++)
        {
            cap+=gas[i];
            cap-=cost[i];
            
            if(cap<0) return -1;
        }
        
        return idx;
    }
};