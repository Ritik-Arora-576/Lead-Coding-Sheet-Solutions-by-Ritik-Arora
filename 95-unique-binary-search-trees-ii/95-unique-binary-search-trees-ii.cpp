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
class Solution {
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
        return store(1,n);
    }
};