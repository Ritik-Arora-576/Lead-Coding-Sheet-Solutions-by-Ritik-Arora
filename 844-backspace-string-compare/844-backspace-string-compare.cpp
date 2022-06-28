// TC: O(N)
// SC: O(1)

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=0;
        int j=0;
        
        while(j<s.length())
        {
            if(s[j]=='#' and i>0) i--;
            else if(s[j]!='#') s[i++]=s[j];
            j++;
        }
        
        s.resize(i);
        
        i=0;
        j=0;
        
        while(j<t.length())
        {
            if(t[j]=='#' and i>0) i--;
            else if(t[j]!='#') t[i++]=t[j];
            j++;
        }
        
        t.resize(i);
        
        return s==t;
    }
};