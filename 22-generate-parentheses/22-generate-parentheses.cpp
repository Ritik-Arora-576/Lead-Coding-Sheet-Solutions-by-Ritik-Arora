// TC: O(2^n)
// SC: O(2^n)

class Solution {
    void store(vector<string> &ans,int &len,int n,int val,string str)
    {
        if(str.length()==len)
        {
            ans.push_back(str);
            return;
        }
        
        if(n>0) store(ans,len,n-1,val-1,str+'(');
        if(val<0) store(ans,len,n,val+1,str+')');
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int len=2*n;
        store(ans,len,n,0,"");
        return ans;
    }
};