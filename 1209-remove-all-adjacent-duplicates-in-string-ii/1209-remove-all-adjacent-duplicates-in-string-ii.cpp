// TC: O(n)
// SC: O(n)

class Solution {
public:
    string removeDuplicates(string str, int k) {
        stack<pair<char,int>> s;
        
        for(char ch:str)
        {
            if(s.empty() or s.top().first!=ch) s.push(make_pair(ch,1));
            else s.push(make_pair(ch,s.top().second+1));
            
            if(s.top().second==k) for(int i=0;i<k;i++) s.pop();
        }
        
        string ans="";
        
        while(!s.empty())
        {
            ans+=s.top().first;
            s.pop();
        }
        
        int i=0;
        int j=ans.length()-1;
        
        while(j>i) swap(ans[i++],ans[j--]);
        
        return ans;
    }
};