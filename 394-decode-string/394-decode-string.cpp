// TC: O(N)
// SC: O(N)

class Solution {
    string solve(string &str,int &i)
    {
        string ans="";
        string num="";
        
        while(i<str.length())
        {
            if(str[i]>='a' and str[i]<='z') ans+=str[i++];
            else if(str[i]>='0' and str[i]<='9') num+=str[i++];
            else if(str[i]=='[')
            {
                i++;
                string temp=solve(str,i);
                int k=stoi(num);
                num="";
                
                while(k--) ans+=temp;
            }
            else
            {
                i++;
                break;
            }
        }
        
        return ans;
    }
public:
    string decodeString(string s) {
        int i=0;
        return solve(s,i);
    }
};