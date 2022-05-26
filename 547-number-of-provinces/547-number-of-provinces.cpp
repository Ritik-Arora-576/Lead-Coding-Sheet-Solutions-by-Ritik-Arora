// Disjoint Set Union

class Solution {
    int find_parent(int i,vector<int> &parent)
    {
        if(i==parent[i]) return i;
        
        return parent[i]=find_parent(parent[i],parent);
    }
    
    void take_union(int i,int j,vector<int> &parent,vector<int> &rank)
    {
        i=find_parent(i,parent);
        j=find_parent(j,parent);
        
        if(rank[i]==rank[j])
        {
            rank[i]++;
            parent[j]=i;
        }
        
        else if(rank[i]>rank[j]) parent[j]=i;
        else parent[i]=j;
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> parent;
        
        for(int i=0;i<n;i++) parent.push_back(i);
        
        vector<int> rank(n,0);
        
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(isConnected[i][j]) take_union(i,j,parent,rank);
        
        int ans=0;
        
        for(int i=0;i<parent.size();i++) if(parent[i]==i) ans++;
        
        return ans;
    }
};