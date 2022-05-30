// Stack Based Solution
// TC: O(N)
// SC: O(N)

class Solution {
    string solve(string str) {
        stack<string> s;
        string temp="";
        
        for(char ch:str)
        {
            if(ch==' ') continue;
            else if(ch>='0' and ch<='9') temp+=ch;
            else if(ch=='-' and temp=="") temp+=ch;
            else
            {
                s.push(temp);
                if(s.size()!=1)
                {
                    int data1=stoi(s.top());
                    s.pop();
                    bool status=true;
                    if(s.top()=="-") status=false;
                    s.pop();
                    int data2=stoi(s.top());
                    s.pop();
                    if(status) s.push(to_string(data1+data2));
                    else s.push(to_string(data2-data1));
                }
                if(ch=='-') s.push("-");
                else s.push("+");
                temp="";
            }
        }
        
        s.push(temp);
        if(s.size()!=1)
        {
            int data1=stoi(s.top());
            s.pop();
            bool status=true;
            if(s.top()=="-") status=false;
            s.pop();
            int data2=stoi(s.top());
            s.pop();
            if(status) s.push(to_string(data1+data2));
            else s.push(to_string(data2-data1));
        }
        
        return s.top();
    }
    
    string iterate(string &s,int &i,string temp)
    {
        if(i==s.length() or s[i]==')') return solve(temp);
        
        if(s[i]=='(') 
        {
            i++;
            temp+=iterate(s,i,"");
        }
        else temp+=s[i];
        
        i++;
        return iterate(s,i,temp);
    }
public:
    int calculate(string str) {
        int i=0;
        return stoi(iterate(str,i,""));
    }
};