// TC: O(n*m)
// SC: O(1)

class Solution {
    int dx[8]={1,-1,0,0,1,-1,1,-1};
    int dy[8]={0,0,1,-1,1,1,-1,-1};
    
    bool check(int i,int j,int &m,int &n,vector<vector<int>>& board)
    {return (i>=0 and j>=0 and i<m and j<n and board[i][j]!=0 and board[i][j]!=4);} 
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row=board.size();
        int col=board[0].size();
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                int n=0;
                for(int k=0;k<8;k++) if(check(i+dx[k],j+dy[k],row,col,board)) n++;
                
                if(board[i][j]==0 and n==3) board[i][j]=4;
                else if(board[i][j]==1 and (n==2 or n==3)) board[i][j]=2;
                else if(board[i][j]==1 and n>3) board[i][j]=3;
            }
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]==4 or board[i][j]==2) board[i][j]=1;
                else board[i][j]=0;
            }
        }
    }
};