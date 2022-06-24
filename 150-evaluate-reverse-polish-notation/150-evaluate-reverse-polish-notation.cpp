// TC: O(N)
// SC: O(N)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for(string str:tokens)
        {
            if(str!="+" and str!="-" and str!="/" and str!="*") s.push(stoi(str));
            else
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                if(str=="+") s.push(b+a);
                else if(str=="*") s.push(b*a);
                else if(str=="/") s.push(b/a);
                else if(str=="-") s.push(b-a);
            }
        }
        
        return s.top();
    }
};