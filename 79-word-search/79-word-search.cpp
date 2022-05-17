// Backtraking Solution

class Solution {
    bool status(vector<vector<char>>& board, string &word,int i,int j,int idx,int &m,int &n)
    {
        if(idx==word.size()) return true;
        if(i<0 or j<0 or i>=m or j>=n or word[idx]!=board[i][j]) return false;
        
        char temp=board[i][j];
        board[i][j]='.';
        
        if(status(board,word,i+1,j,idx+1,m,n) or status(board,word,i-1,j,idx+1,m,n) or status(board,word,i,j-1,idx+1,m,n) or status(board,word,i,j+1,idx+1,m,n)) return true;
        
        board[i][j]=temp;
        
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(board[i][j]==word[0] and status(board,word,i,j,0,m,n)) return true;
        }
        
        return false;
    }
};