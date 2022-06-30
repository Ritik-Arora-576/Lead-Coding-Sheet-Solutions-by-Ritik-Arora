// TC: O(2^N)

class Solution {
    bool isPalindrome(string &s)
    {
        int i=0;
        int j=s.length()-1;
        
        while(j>i) if(s[i++]!=s[j--]) return false;
        
        return true;
    }
    
    void store(string &s,vector<vector<string>> &ans,int i,int j,vector<string> &temp)
    {
        if(j==s.length())
        {
            if(i==s.length()) ans.push_back(temp);
            return;
        }
        
        string str=s.substr(i,j-i+1);
        
        if(isPalindrome(str))
        {
            temp.push_back(s.substr(i,j-i+1));
            store(s,ans,j+1,j+1,temp);
            temp.pop_back();
        }
        
        store(s,ans,i,j+1,temp);
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        store(s,ans,0,0,temp);
        return ans;
    }
};