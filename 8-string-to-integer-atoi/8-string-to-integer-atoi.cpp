// TC: O(s.length())
// SC: O(1)

class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        int i=0;
        
        while(s[i]==' ') i++;
        
        bool status=false;
        
        if(s[i]=='-')
        {
            i++;
            status=true;
        }
        
        else if(s[i]=='+') i++;
        
        while(s[i]=='0') i++;
        
        while(i<s.length() and s[i]>='0' and s[i]<='9')
        {
            ans=(ans*10)+(s[i++]-'0');
            if(status and -1*ans<=INT_MIN) return INT_MIN;
            if(!status and ans>=INT_MAX) return INT_MAX;
        }
        
        if(status) ans*=-1;
        
        return ans;
    }
};