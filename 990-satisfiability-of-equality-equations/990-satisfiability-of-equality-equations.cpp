// DSU approach

class Solution {
    char find_parent(char ch,vector<char> &parent)
    {
        if(ch==parent[ch-'a']) return ch;
        return parent[ch-'a']=find_parent(parent[ch-'a'],parent);
    }
    
    bool same(char &a,char &b,vector<char> &parent) {return find_parent(a,parent)==find_parent(b,parent);}
    
    void take_union(char a,char b,vector<char> &parent,vector<int> &rank)
    {
        a=find_parent(a,parent);
        b=find_parent(b,parent);
        
        if(rank[a-'a']>rank[b-'a']) parent[b-'a']=a;
        else if(rank[a-'a']<rank[b-'a']) parent[a-'a']=b;
        else
        {
            rank[a-'a']++;
            parent[b-'a']=a;
        }
    }
    
public:
    bool equationsPossible(vector<string>& equations) {
        vector<char> parent;
        vector<int> rank(26,0);
        
        for(char ch='a';ch<='z';ch++)
            parent.push_back(ch);
        
        
        for(string str:equations)
        {
            char a=str[0];
            char b=str[3];
            bool status=false;
            if(str[1]=='=') status=true;
            
            if(status and !same(a,b,parent)) take_union(a,b,parent,rank);
        }
        
        for(string str:equations)
        {
            char a=str[0];
            char b=str[3];
            bool status=false;
            if(str[1]=='=') status=true;
            
            if(!status and same(a,b,parent)) return false;
        }
        
        return true;
    }
};