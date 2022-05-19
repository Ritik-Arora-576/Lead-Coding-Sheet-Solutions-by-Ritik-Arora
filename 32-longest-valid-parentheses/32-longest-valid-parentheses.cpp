// Stack Based Solution
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int longestValidParentheses(string str) {
        int ans=0;
        stack<int> s;
        
        for(int i=0;i<str.length();i++)
        {
            if(s.empty() or str[i]=='(' or str[s.top()]==')') s.push(i);
            else
            {
                s.pop();
                int temp=0;
                if(s.empty()) temp=i+1;
                else temp=i-s.top();
                
                ans=max(ans,temp);
            }
        }
        
        return ans;
    }
};