class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int> s;
        int ans=0;
        
        for(int i=0;i<str.length();i++)
        {
            if(s.empty() or str[i]=='(' or str[s.top()]==')') s.push(i);
            else
            {
                s.pop();
                if(!s.empty()) ans=max(ans,i-s.top());
                else ans=max(ans,i+1);
            }
        }
        
        return ans;
    }
};