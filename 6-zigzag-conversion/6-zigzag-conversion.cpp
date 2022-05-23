// TC: O(N)
// SC: O(N)

class Solution {
public:
    string convert(string str, int numRows) {
        if(numRows==1) return str;
        
        int i=0;
        int diff1=2*(numRows-1);
        int diff2=0;
        string ans="";
        int len=str.length();
        
        while(i<min(numRows,len))
        {
            int s=i;
            i++;
            ans+=str[s];
            
            while(s<str.length())
            {
                if(diff1!=0) s+=diff1;
                if(s<str.length() and diff1!=0) ans+=str[s];
                if(diff2!=0) s+=diff2;
                if(s<str.length() and diff2!=0) ans+=str[s];
            }
            
            diff1-=2;
            diff2+=2;
        }
        
        return ans;
    }
};