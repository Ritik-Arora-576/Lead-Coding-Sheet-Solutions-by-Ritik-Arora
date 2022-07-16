/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Partition DP

class Solution {
    // recursive call
    vector<TreeNode*> store(int s,int e)
    {
        vector<TreeNode*> ans;
        
        if(s>e) return ans={NULL};
        for(int i=s;i<=e;i++)
        {
            vector<TreeNode*> left=store(s,i-1);
            vector<TreeNode*> right=store(i+1,e);
            
            for(int k=0;k<left.size();k++)
            {
                for(int j=0;j<right.size();j++)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=left[k];
                    root->right=right[j];
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> dp[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) dp[i][j]={new TreeNode(i+1)};
                else if(i>j) dp[i][j]={NULL};
                else dp[i][j]={};
            }
        }
        
        for(int j=1;j<n;j++)
        {
            for(int i=j-1;i>=0;i--)
            {
                for(int k=i;k<=j;k++)
                {
                    vector<TreeNode*> left,right;
                    if(i>k-1) left={NULL};
                    else left=dp[i][k-1];
                    if(k+1>j) right={NULL};
                    else right=dp[k+1][j];
                    
                    for(auto l:left)
                    {
                        for(auto r:right)
                        {
                            TreeNode* root=new TreeNode(k+1);
                            root->left=l;
                            root->right=r;
                            dp[i][j].push_back(root);
                        }
                    }
                }
            }
        }
        
        return dp[0][n-1];
    }
};