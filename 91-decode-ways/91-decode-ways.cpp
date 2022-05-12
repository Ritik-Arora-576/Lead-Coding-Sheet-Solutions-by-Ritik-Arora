class Solution {
    // Recursive Solution
    // TC: O(2^N)
    
    int solve(string &s,string nums,int i)
    {
        if(nums=="0") return 0;
        if(nums!="" and stoi(nums)>26) return 0;
        if(i==s.length()) return 1;
        
        if(nums=="") return solve(s,nums+s[i],i+1);
        return solve(s,nums+s[i],i+1)+solve(s,s.substr(i,1),i+1);
    }
    
public:
    // DP solution
    // TC: O(N)
    // SC: O(1)
    
    int numDecodings(string s) {
        int b=1;
        int a;
        if(s[s.length()-1]=='0') a=0;
        else a=1;
        
        for(int i=s.length()-2;i>=0;i--)
        {
            if(s[i]=='0') b=a,a=0;
            else
            {
                string str=s.substr(i,2);
                int temp;
                if(stoi(str)<=26) temp=a+b;
                else temp=a;
                
                b=a;
                a=temp;
            }
        }
        
        return a;
    }
};