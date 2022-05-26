// TC: O(m*n)
// SC: O(m*n)

class Solution {
    void iterate(int i,int j,vector<vector<char>>& board,int &row,int &col,bool &status,vector<vector<bool>> &visited)
    {
        if(i<0 or j<0 or i==row or j==col)
        {
            status=false;
            return;
        }
        
        if(visited[i][j] or board[i][j]=='X') return;
        
        visited[i][j]=true;
        
        iterate(i-1,j,board,row,col,status,visited);
        iterate(i+1,j,board,row,col,status,visited);
        iterate(i,j-1,board,row,col,status,visited);
        iterate(i,j+1,board,row,col,status,visited);
    }
    
    void convert(int i,int j,int &row,int &col,vector<vector<char>>& board)
    {
        if(i<0 or j<0 or i==row or j==col or board[i][j]=='X') return;
        board[i][j]='X';
        
        convert(i+1,j,row,col,board);
        convert(i-1,j,row,col,board);
        convert(i,j-1,row,col,board);
        convert(i,j+1,row,col,board);
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        
        vector<vector<bool>> visited;
        
        for(int i=0;i<row;i++)
        {
            vector<bool> v(col,false);
            visited.push_back(v);
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='O' and !visited[i][j])
                {
                    bool status=true;
                    iterate(i,j,board,row,col,status,visited);
                    if(status) convert(i,j,row,col,board);
                }
            }
        }
    }
};