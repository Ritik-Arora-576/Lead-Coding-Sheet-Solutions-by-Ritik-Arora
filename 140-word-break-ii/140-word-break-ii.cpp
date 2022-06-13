class Solution {
    // recursive call
    void store(string &str,vector<string> &ans,vector<string> &temp,unordered_set<string> &s,string temp_str,int i)
    {
        if(i==str.length())
        {
            if(s.find(temp_str)!=s.end())
            {
                string data="";
                for(int i=0;i<temp.size();i++) data+=(temp[i]+" ");
                ans.push_back(data+temp_str);
            }
            
            return;
        }
        
        store(str,ans,temp,s,temp_str+str[i],i+1);
        
        if(s.find(temp_str)!=s.end())
        {
            temp.push_back(temp_str);
            string data="";
            store(str,ans,temp,s,data+str[i],i+1);
            temp.pop_back();
        }
    }
    
public:
    vector<string> wordBreak(string str, vector<string>& wordDict) {
//         vector<string> ans;
//         vector<string> temp;
        
        unordered_set<string> s;
        for(string data:wordDict) s.insert(data);
        
//         store(str,ans,temp,s,temp_str,0);
//         return ans;
        
        unordered_map<int,vector<string>> m;
        vector<int> v;
        
        v.push_back(str.length());
        
        for(int i=str.length()-1;i>=0;i--)
        {
            bool check=false;
            for(int j:v)
            {
                if(s.find(str.substr(i,j-i))!=s.end())
                {
                    check=true;
                    if(j==str.length()) m[i].push_back(str.substr(i,j-i));
                    else for(string data:m[j]) m[i].push_back(str.substr(i,j-i)+" "+data);
                }
            }
            
            if(check) v.push_back(i);
        }
        
        if(m.find(0)==m.end()) return {};
        return m[0];
    }
};