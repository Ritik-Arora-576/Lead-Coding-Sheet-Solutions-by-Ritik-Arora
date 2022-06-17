// TC: O(N)
// SC: O(N)

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n,0);
        for(auto data:trust) indegree[data[1]-1]++;
        int count=0;
        int sus=0;
        
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==n-1)
            {
                count++;
                sus=i+1;
            }
        }
        
        if(count!=1) return -1;
        
        for(auto data:trust) if(data[0]==sus) return -1;
        
        return sus;
    }
};