// TC: O(N)
// SC: O(1)

class Solution {
public:
    string reverseWords(string str) {
        int i=0;
        int j=str.length()-1;
        
        while(str[i]==' ') i++;
        while(str[j]==' ') j--;
        
        int s=i;
        int e=j;
        
        while(e>s) swap(str[e--],str[s++]);
        
        s=i;
        e=i;
        bool count=true;
        
        while(e<=j)
        {
            if(str[e]!=' ')
            {
                count=true;
                swap(str[s],str[e]);
                s++;
            }
            
            else if(str[e]==' ' and count)
            {
                count=false;
                swap(str[s],str[e]);
                s++;
            }
            
            e++;
        }
        
        j=s-1;
        
        s=i;
        e=i;
        
        while(true)
        {
            if(e==j)
            {
                int temp1=s;
                int temp2=e;
                while(temp2>temp1) swap(str[temp2--],str[temp1++]);
                break;
            }
            
            if(str[e]==' ')
            {
                int temp1=s;
                s=e+1;
                int temp2=e-1;
                while(temp2>temp1) swap(str[temp2--],str[temp1++]);
            }
            
            e++;
        }
        
        return str.substr(i,j-i+1);
    }
};