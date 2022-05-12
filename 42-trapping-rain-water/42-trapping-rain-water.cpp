// TC: O(N)
// SC: O(N)
// Stack based solution

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int ans=0;
        
        for(int i=0;i<height.size();i++)
        {
            while(!s.empty() and height[i]>=height[s.top()])
            {
                int data=height[s.top()];
                s.pop();

                if(!s.empty()) ans+=(i-s.top()-1)*(min(height[s.top()],height[i])-data);
            }

            s.push(i);
        }
        
        return ans;
    }
};