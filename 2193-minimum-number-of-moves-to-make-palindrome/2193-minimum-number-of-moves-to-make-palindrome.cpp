class Solution {
public:
    int minMovesToMakePalindrome(string &str) {
        unordered_map<char,int> m;
        int n=str.length();

        for(char ch:str) m[ch]++;
        bool track=true;

        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second%2)
            {
                if(n%2==0 or (n%2 and !track)) return -1;
                else track=false;
            }
        }

        int ans=0;

        for(int i=0;i<n/2;i++)
        {
            int l=i,r=n-i-1;
            while(l<r)
            {
                if(str[l]==str[r]) break;
                else r--;
            }

            if(r!=l)
            {
                for(int k=r;k<n-l-1;k++)
                {
                    char ch=str[k];
                    str[k]=str[k+1];
                    str[k+1]=ch;
                    ans++;
                }
            }

            else
            {
                char ch=str[l];
                str[l]=str[l+1];
                str[l+1]=ch;
                ans++;
                i--;
            }
        }

        return ans;
        }
};