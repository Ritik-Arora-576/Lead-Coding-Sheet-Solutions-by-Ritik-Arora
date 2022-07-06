// TC: O(nlogn)
// SC: O(k)

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> q;
        int ans=0;
        
        for(int i=1;i<heights.size();i++)
        {
            int diff=heights[i]-heights[i-1];
            if(diff<=0) 
            {
                ans=i;
                continue;
            }
            
            bricks-=diff;
            q.push(diff);
            
            if(bricks<0)
            {
                if(ladders)
                {
                    ladders--;
                    bricks+=q.top();
                    q.pop();
                    ans=i;
                }
                
                else break;
            }
            
            else ans=i;
        }
        
        return ans;
    }
};