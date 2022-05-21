// TC: O(N)
// SC: O(1)

class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        
        while(j>i and s[i]==s[j]) i++,j--;
        
        int i1=i;
        int j1=j-1;
        bool status=true;
        
        while(i1<j1) {
            if(s[i1++]!=s[j1--]) 
            {
                status=false;
                break;
            }
        }
        
        if(status) return true;
        
        i1=i+1;
        j1=j;
        status=true;
        
        while(i1<j1) {
            if(s[i1++]!=s[j1--]) 
            {
                status=false;
                break;
            }
        }
        
        return status;
    }
};