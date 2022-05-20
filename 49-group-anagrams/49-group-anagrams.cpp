// Hashmap Solution

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>,vector<string>> m;
        
        for(auto str:strs)
        {
            vector<int> temp(26,0);
            for(char ch:str)
            {
                int idx=ch-'a';
                temp[idx]++;
            }
            m[temp].push_back(str);
        }
        
        for(auto temp: m) ans.push_back(temp.second);
        
        return ans;
    }
};