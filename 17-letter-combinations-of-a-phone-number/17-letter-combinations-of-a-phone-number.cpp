// Backtracking Solution

vector<string> key={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

class Solution {
    void store(vector<string> &ans,int i,string &digits,string str)
    {
        if(i==digits.length())
        {
            ans.push_back(str);
            return;
        }
        
        int k=digits[i]-'0';
        
        for(char ch:key[k]) store(ans,i+1,digits,str+ch);
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()!=0) store(ans,0,digits,"");
        return ans;
    }
};