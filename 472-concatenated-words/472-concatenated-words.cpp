// TC: O(N*str.length())
// SC: O(N)

class Solution {
    bool isConcatenated(string &str,unordered_set<string> &s,int k)
    {
        if(k==str.length()) return true;
        
        string temp="";
        for(int i=k;i<str.length();i++)
        {
            temp+=str[i];
            if(s.find(temp)!=s.end() and isConcatenated(str,s,i+1)) return true;
        }
        
        return false;
    }
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s;
        for(string str:words) s.insert(str);
        vector<string> v;
        
        for(string str:words)
        {
            s.erase(str);
            if(isConcatenated(str,s,0)) v.push_back(str);
            s.insert(str);
        }
        
        return v;
    }
};