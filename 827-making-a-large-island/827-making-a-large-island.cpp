// TC: O(n*m)
// SC: O(n*m)

class Solution {
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    
    int area(vector<vector<int>>& grid,vector<vector<pair<int,int>>> &v,int i,int j,int &row,int &col,int &cluster)
    {
        if(i==row or i<0 or j==col or j<0 or grid[i][j]==0) return 0;
        grid[i][j]=0;
        v[i][j]=make_pair(-1,cluster);
        return area(grid,v,i-1,j,row,col,cluster)+area(grid,v,i+1,j,row,col,cluster)+area(grid,v,i,j-1,row,col,cluster)+area(grid,v,i,j+1,row,col,cluster)+1;
    }
    
    void store(int &data,int &cluster,vector<vector<pair<int,int>>> &v,vector<vector<int>>& grid,int i,int j,int &row,int &col)
    {
        if(i==row or i<0 or j==col or j<0 or v[i][j].first==0 or v[i][j].first!=-1) return;
        v[i][j]=make_pair(data,cluster);
        store(data,cluster,v,grid,i+1,j,row,col);
        store(data,cluster,v,grid,i-1,j,row,col);
        store(data,cluster,v,grid,i,j+1,row,col);
        store(data,cluster,v,grid,i,j-1,row,col);
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> temp=grid;
        vector<vector<pair<int,int>>> v(row,vector<pair<int,int>> (col));
        int cluster=1;
        int ans=0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==0) v[i][j]=make_pair(0,0);
            }
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j])
                {
                    int data=area(grid,v,i,j,row,col,cluster);
                    store(data,cluster,v,grid,i,j,row,col);
                    ans=max(ans,data);
                    cluster++;
                }
            }
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(temp[i][j]==0)
                {
                    unordered_set<int> s;
                    int data=1;
                    for(int k=0;k<4;k++)
                    {
                        int x1=i+dx[k];
                        int y1=j+dy[k];
                        
                        if(x1>=0 and x1<row and y1>=0 and y1<col)
                        {
                            if(s.find(v[x1][y1].second)==s.end())
                            {
                                data+=v[x1][y1].first;
                                s.insert(v[x1][y1].second);
                            }
                        }
                    }
                    
                    ans=max(ans,data);
                }
            }
        }
        
        return ans;
    }
};