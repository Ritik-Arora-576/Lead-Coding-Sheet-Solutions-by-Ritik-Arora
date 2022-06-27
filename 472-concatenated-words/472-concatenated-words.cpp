// TC: O(N*str.length())
// SC: O(N)

class Solution {
    bool isConcatenated(string &str,unordered_set<string> &s)
    {
        vector<int> v;
        v.push_back(str.length());
        
        for(int i=str.length();i>=0;i--)
        {
            for(int data:v)
            {
                if(s.find(str.substr(i,data-i))!=s.end())
                {
                    v.push_back(i);
                    break;
                }
            }
        }
        
        return v[v.size()-1]==0;
    }
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s;
        for(string str:words) s.insert(str);
        vector<string> v;
        
        for(string str:words)
        {
            s.erase(str);
            if(isConcatenated(str,s)) v.push_back(str);
            s.insert(str);
        }
        
        return v;
    }
};