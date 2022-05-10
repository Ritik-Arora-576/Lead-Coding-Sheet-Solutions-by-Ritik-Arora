// Sliding Window + Two Pointers Approach
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        
        for(int i=0;i<k;i++) sum+=cardPoints[i];
        int ans=sum;
        
        int start=k-1;
        int end=cardPoints.size()-1;
        
        while(start>=0)
        {
            sum=sum-cardPoints[start]+cardPoints[end];
            ans=max(ans,sum);
            start--;
            end--;
        }
        
        return ans;
    }
};
