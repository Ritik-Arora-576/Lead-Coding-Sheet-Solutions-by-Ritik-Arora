// TC: O(N)
// SC: O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26,0);
        int i=0;
        int j=0;
        int maxi=0;
        int ans=0;
        
        while(j<s.length())
        {
            v[s[j]-'A']++;
            maxi=max(maxi,v[s[j]-'A']);
            int diff=(j-i+1)-maxi;
            
            if(diff<=k) ans=max(ans,j-i+1);
            else
            {
                while(diff>k)
                {
                    v[s[i++]-'A']--;
                    for(int data:v) maxi=max(maxi,data);
                    diff=(j-i+1)-maxi;
                }
            }
            
            j++;
        }
        
        return ans;
    }
};