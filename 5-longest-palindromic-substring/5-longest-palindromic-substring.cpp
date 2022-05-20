// TC: O(N^2)
// SC: O(1)

class Solution {
public:
    string longestPalindrome(string str) {
        int len=0;
        int start=-1;
        
        for(int i=0;i<str.length();i++)
        {
            int s=i;
            int e=i;
            
            while(s>=0 and e<str.length())
            {
                if(str[s]!=str[e]) break;
                if(len<e-s+1) len=e-s+1,start=s;
                s--;
                e++;
            }
            
            if(i==str.length()-1) break;
            
            s=i;
            e=i+1;
            
            while(s>=0 and e<str.length())
            {
                if(str[s]!=str[e]) break;
                if(len<e-s+1) len=e-s+1,start=s;
                s--;
                e++;
            }
        }
        
        return str.substr(start,len);
    }
};