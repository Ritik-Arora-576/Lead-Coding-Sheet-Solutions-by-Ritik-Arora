class Solution {
    bool status(string &s,int i,string temp,unordered_set<string> &m)
    {
        if(i==s.length())
        {
            if(temp=="") return true;
            if(temp!="" and m.find(temp)!=m.end()) return true;
            
            return false;
        }
        
        if(m.find(temp)!=m.end()) return status(s,i+1,s.substr(i,1),m) or status(s,i+1,temp+s[i],m);
        
        return status(s,i+1,temp+s[i],m);
    }
    
public:
    // 1D DP approach
    // TC: O(N^2)
    // SC: O(N)
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> m;
        
        for(string str:wordDict) m.insert(str);
        
        vector<int> trueIdx;
        trueIdx.push_back(s.length());
        
        for(int i=s.length()-1;i>=0;i--)
        {
            for(int j=trueIdx.size()-1;j>=0;j--)
            {
                if(m.find(s.substr(i,trueIdx[j]-i))!=m.end())
                {
                    trueIdx.push_back(i);
                    break;
                }
            }
        }
        
        return trueIdx[trueIdx.size()-1]==0;
    }
};