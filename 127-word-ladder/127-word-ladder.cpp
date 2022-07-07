class Solution {
    bool similar(string &str1,string &str2)
    {
        int diff=0;
        for(int i=0;i<str1.length();i++)
        {
            if(str1[i]!=str2[i]) diff++;
            if(diff==2) return false;
        }
        return diff==1;
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for(string str:wordList) s.insert(str);
        queue<pair<string,int>> q;
        q.push(make_pair(beginWord,1));
        int ans=0;
        
        while(!q.empty())
        {
            string str1=q.front().first;
            int dist=q.front().second;
            q.pop();
            
            if(str1==endWord)
            {
                ans=dist;
                break;
            }
            
            vector<string> temp;
            for(string str:s)
            {
                if(similar(str,str1))
                {
                    q.push(make_pair(str,dist+1));
                    temp.push_back(str);
                }
            }
            
            for(string str:temp) s.erase(str);
        }
        
        return ans;
    }
};