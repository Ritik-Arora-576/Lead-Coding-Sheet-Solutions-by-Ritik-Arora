class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int ans=0;
        string str=to_string(num);
        
        for(int i=0;i<=str.length()-k;i++)
        {
            int div=stoi(str.substr(i,k));
            if(div!=0 and num%div==0) ans++;
        }
        return ans;
    }
};