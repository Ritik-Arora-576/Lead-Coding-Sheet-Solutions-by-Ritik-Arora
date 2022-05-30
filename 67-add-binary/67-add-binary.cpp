// TC: O(max(a.length(),b.length()))
// SC: O(abs(a.length()-b.length()))

class Solution {
public:
    string addBinary(string a, string b) {
        while(a.length()>b.length())
            b='0'+b;
        while(a.length()<b.length())
            a='0'+a;
        
        bool status=false;
        
        for(int i=a.length()-1;i>=0;i--)
        {
            if((a[i]=='1' and b[i]=='1' and !status) or (a[i]=='1' and b[i]=='0' and status) or (a[i]=='0' and b[i]=='1' and status))
            {
                b[i]='0';
                status=true;
            }
            
            else if((a[i]=='0' and b[i]=='1' and !status) or (a[i]=='1' and b[i]=='0' and !status) or (a[i]=='0' and b[i]=='0' and status))
            {
                b[i]='1';
                status=false;
            }
        }
        
        if(status) return '1'+b;
        return b;
    }
};