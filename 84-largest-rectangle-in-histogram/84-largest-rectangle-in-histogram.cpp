// TC: O(N)
// SC: O(N)
// Stack based solution

class Solution {
    int max(int a,int b) {return a>b?a:b;}
    
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int ans=0;
        
        for(int i=0;i<heights.size();i++)
        {   
            if(!s.empty() and heights[i]<heights[s.top()])
            {
                while(!s.empty() and heights[s.top()]>heights[i])
                {
                    int data=heights[s.top()];
                    s.pop();
                    
                    if(!s.empty()) ans=max(ans,data*(i-s.top()-1));
                    else ans=max(ans,data*i);
                }
            }
            s.push(i);
        }
        
        while(!s.empty())
        {
            int data=heights[s.top()];
            s.pop();
            if(!s.empty()) ans=max(ans,data*(heights.size()-s.top()-1));
            else ans=max(ans,data*heights.size());
        }
        
        return ans;
    }
};