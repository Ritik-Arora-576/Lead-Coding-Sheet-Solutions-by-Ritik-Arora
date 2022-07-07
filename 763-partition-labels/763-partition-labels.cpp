// TC: O(N)
// SC: O(N)

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int,int>> v;
        for(int i=0;i<26;i++) v.push_back(make_pair(-1,-1));
        
        for(int i=0;i<s.length();i++)
        {
            int idx=s[i]-'a';
            if(v[idx].first==-1) v[idx].first=i,v[idx].second=i;
            else v[idx].second=i;
        }
        
        sort(v.begin(),v.end());
        vector<pair<int,int>> temp;
        int i=0;
        
        while(i<v.size())
        {
            if(v[i].first==-1) i++;
            else if(temp.size()==0) temp.push_back(v[i++]);
            else
            {
                if(v[i].first>temp[temp.size()-1].second) temp.push_back(v[i++]);
                else temp[temp.size()-1].second=max(temp[temp.size()-1].second,v[i++].second);
            }
        }
        
        vector<int> ans;
        
        for(auto p:temp) ans.push_back(p.second-p.first+1);
        
        return ans;
    }
};