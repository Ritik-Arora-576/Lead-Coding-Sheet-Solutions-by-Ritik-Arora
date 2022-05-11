// TC: O(N^2)
// SC: O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int sr=0;
        int er=matrix.size()-1;
        int sc=0;
        int ec=er;
        
        while(sr<er)
        {
            for(int col=sc;col<ec;col++)
            {
                swap(matrix[sr][col],matrix[col][ec]);
                swap(matrix[sr][col],matrix[er][matrix.size()-1-col]);
                swap(matrix[sr][col],matrix[matrix.size()-1-col][sc]);
            }
            sr++;
            sc++;
            er--;
            ec--;
        }
    }
};