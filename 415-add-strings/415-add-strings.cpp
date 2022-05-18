// TC: O(max(num1.length(),num2.length()))
// SC: O(abs(num1.length()-num2.length()))

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.length()>num2.length())
        {
            int len=num1.length()-num2.length();
            while(len--) num2='0'+num2;
        }
        
        else
        {
            int len=num2.length()-num1.length();
            while(len--) num1='0'+num1;
        }
        
        int rem=0;
        
        for(int i=num2.length()-1;i>=0;i--)
        {
            int data1=num1[i]-'0';
            int data2=num2[i]-'0';
            data1+=data2;
            data1+=rem;
            rem=data1/10;
            data1%=10;
            char ch=data1+'0';
            num1[i]=ch;
        }
        
        if(rem) num1='1'+num1;
        
        return num1;
    }
};