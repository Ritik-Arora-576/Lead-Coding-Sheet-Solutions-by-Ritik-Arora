// Two Pointers Approach
// TC: O(N^2)
// SC: O(1)

class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        
        for(int m=0;m<s.length();m++)
        {
            int i=m;
            int j=m;
            
            while(i>=0 and j<s.length() and s[i--]==s[j++]) ans++;
            
            i=m-1;
            j=m;
            
            while(i>=0 and j<s.length() and s[i--]==s[j++]) ans++;
        }
        
        return ans;
    }
};