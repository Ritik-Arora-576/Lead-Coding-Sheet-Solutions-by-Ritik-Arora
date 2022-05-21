// TC: O(N)
// SC: O(1)

class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        int prev=0;
        
        unordered_map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        
        for(int i=s.length()-1;i>=0;i--)
        {
            if(m[s[i]]>=prev) ans+=m[s[i]];
            else ans-=m[s[i]];
            prev=m[s[i]];
        }
        
        return ans;
    }
};