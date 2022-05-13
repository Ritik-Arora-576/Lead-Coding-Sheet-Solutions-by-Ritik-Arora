class Solution {
    int max(int a,int b) {return a>b?a:b;}
    
    int maximumRectangle(vector<int> &dp)
    {
        stack<int> s;
        int ans=0;
        
        for(int i=0;i<dp.size();i++)
        {
            while(!s.empty() and dp[i]<=dp[s.top()])
            {
                int data=dp[s.top()];
                s.pop();
                
                if(!s.empty()) ans=max(ans,data*(i-s.top()-1));
                else ans=max(ans,data*i);
            }
            
            s.push(i);
        }
        
        while(!s.empty())
        {
            int data=dp[s.top()];
            s.pop();

            if(!s.empty()) ans=max(ans,data*(dp.size()-s.top()-1));
            else ans=max(ans,data*dp.size());
        }
        
        return ans;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> dp(col,0);
        int ans=0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]=='1') dp[j]++;
                else dp[j]=0;
            }
            
            ans=max(ans,maximumRectangle(dp));
        }
        
        return ans;
    }
};