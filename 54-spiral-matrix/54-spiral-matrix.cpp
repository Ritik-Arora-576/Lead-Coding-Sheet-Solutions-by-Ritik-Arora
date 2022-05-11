// TC: O(N^2)
// SC: O(N^2)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int sr=0;
        int er=matrix.size()-1;
        int sc=0;
        int ec=matrix[0].size()-1;
        vector<int> ans;
        
        while(true)
        {
            for(int col=sc;col<=ec;col++) ans.push_back(matrix[sr][col]);
            sr++;
            if(sr>er) break;
            for(int row=sr;row<=er;row++) ans.push_back(matrix[row][ec]);
            ec--;
            if(sc>ec) break;
            for(int col=ec;col>=sc;col--) ans.push_back(matrix[er][col]);
            er--;
            if(sr>er) break;
            for(int row=er;row>=sr;row--) ans.push_back(matrix[row][sc]);
            sc++;
            if(sc>ec) break;
        }
        
        return ans;
    }
};