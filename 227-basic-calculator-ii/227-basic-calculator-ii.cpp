// Stack based solution
// TC: O(str.length())
// SC: O(str.length())

class Solution {
public:
    int calculate(string str) {
        stack<int> s;
        string temp="";
        
        for(char ch:str)
        {
            if(ch>='0' and ch<='9')
                temp+=ch;
            
            else if(ch==' ') continue;
            
            else
            {
                int data=stoi(temp);
                temp="";
                
                if(!s.empty() and (s.top()==-3 or s.top()==-4))
                {
                    if(s.top()==-3)
                    {
                        s.pop();
                        int data1=s.top();
                        s.pop();
                        s.push(data1*data);
                    }
                    
                    if(s.top()==-4)
                    {
                        s.pop();
                        int data1=s.top();
                        s.pop();
                        s.push(data1/data);
                    }
                }
                
                else s.push(data);
                
                if(ch=='+') s.push(-1);
                else if(ch=='-') s.push(-2);
                else if(ch=='*') s.push(-3);
                else if(ch=='/') s.push(-4);
            }
        }
        
        int data=stoi(temp);
        temp="";
        
        if(!s.empty() and (s.top()==-3 or s.top()==-4))
        {
            if(s.top()==-3)
            {
                s.pop();
                int data1=s.top();
                s.pop();
                s.push(data1*data);
            }

            if(s.top()==-4)
            {
                s.pop();
                int data1=s.top();
                s.pop();
                s.push(data1/data);
            }
        }
        
        else s.push(data);
        
        stack<int> s1;
        
        while(!s.empty())
        {
            s1.push(s.top());
            s.pop();
        }
        
        while(s1.size()!=1)
        {
            data=s1.top();
            s1.pop();
            int status=s1.top();
            s1.pop();
            int data1=s1.top();
            s1.pop();
            
            if(status==-1) s1.push(data1+data);
            else s1.push(data-data1);
        }
        
        return s1.top();
    }
};