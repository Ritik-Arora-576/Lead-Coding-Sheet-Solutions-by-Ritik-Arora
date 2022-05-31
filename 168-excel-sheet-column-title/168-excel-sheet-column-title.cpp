// TC: O(str.length())
// SC: O(str.length())

class Solution {
public:
    string convertToTitle(int num) {
        string str="";
        
        while(num)
        {
            int data=num%26;
            if(data==0)
            {
                str+='Z';
                num=(num/26)-1;
            }
            
            else
            {
                data--;
                char ch='A'+data;
                str+=ch;
                num/=26;
            }
        }
        
        int i=0;
        int j=str.length()-1;
        
        while(j>i) swap(str[i++],str[j--]);
        
        return str;
    }
};