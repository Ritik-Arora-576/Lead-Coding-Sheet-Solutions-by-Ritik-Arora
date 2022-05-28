// TC: O(N)
// SC: O(N)

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        stack<int> s;
        
        for(char ch:num)
        {
            int data=ch-'0';
            
            while(!s.empty() and k>0 and data<s.top())
            {
                s.pop();
                k--;
            }
            
            s.push(data);
        }
        
        while(!s.empty())
        {
            char ch=s.top()+'0';
            s.pop();
            ans+=ch;
        }
        
        int st=0;
        int e=ans.size()-1;
        
        while(st<e) swap(ans[st++],ans[e--]);
        
        int i=0;
        
        while(i<ans.size() and ans[i]=='0') i++;
        
        if(k>=ans.size()-i) return "0";
        
        return ans.substr(i,ans.size()-i-k);
    }
};