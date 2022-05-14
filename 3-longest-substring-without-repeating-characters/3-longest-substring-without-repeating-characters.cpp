// Sliding Window Solution
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        unordered_map<int,bool> v;
        int ans=0;
        
        while(j<s.length())
        {
            while(v[s[j]-'a']) v[s[i++]-'a']=false;
            ans=max(ans,j-i+1);
            v[s[j++]-'a']=true;
        }
        
        return ans;
    }
};