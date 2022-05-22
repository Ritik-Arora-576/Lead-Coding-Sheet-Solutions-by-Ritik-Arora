// TC: O(N)
// SC: O(N)

class Solution {
public:
    string minRemoveToMakeValid(string str) {
        string ans="";
        vector<int> v;
        
        for(int i=0;i<str.length();i++)
        {
            if(str[i]>='a' and str[i]<='z') continue;
            
            if(v.size()==0 or str[i]=='(' or str[v[v.size()-1]]==')') v.push_back(i);
            else if(str[i]==')' and str[v[v.size()-1]]=='(') v.pop_back();
        }
        
        int idx=0;
        
        for(int i=0;i<str.length();i++)
        {
            if(idx<v.size() and v[idx]==i)
            {
                idx++;
                continue;
            }
            
            ans+=str[i];
        }
    
        
        return ans;
    }
};