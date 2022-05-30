// TC: O(N)
// SC: O(1)

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i=0;
        int ans=0;
        
        while(i<neededTime.size())
        {
            char ch=colors[i];
            int maxCost=0;
            int sum=0;
            
            while(i<neededTime.size() and colors[i]==ch)
            {
                maxCost=max(maxCost,neededTime[i]);
                sum+=neededTime[i];
                i++;
            }
            
            ans+=(sum-maxCost);
        }
        
        return ans;
    }
};