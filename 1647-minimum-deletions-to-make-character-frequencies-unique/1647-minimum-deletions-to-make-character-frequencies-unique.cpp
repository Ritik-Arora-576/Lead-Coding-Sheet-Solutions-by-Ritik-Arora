class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26,0);
        vector<int> freq(100001,0);
        
        for(char ch:s) v[ch-'a']++;
        for(int data:v) if(data!=0) freq[data]++;
        
        int ans=0;
        
        for(int i=100000;i>0;i--)
            if(freq[i]>1) ans+=freq[i]-1,freq[i-1]+=freq[i]-1;
        
        return ans;
    }
};