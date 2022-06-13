/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// TC: O(N)
// SC: O(1)

class Solution {
    bool lca(TreeNode* &root, TreeNode* &p, TreeNode* &q, TreeNode* &ans)
    {
        if(root==NULL) return false;
        if(root==p or root==q)
        {
            ans=root;
            return true;
        }
       
        bool left=lca(root->left,p,q,ans);
        bool right=lca(root->right,p,q,ans);
        
        if(left and right)
        {
            ans=root;
            return true;
        }
        
        return (left or right);
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        lca(root,p,q,ans);
        return ans;
    }
};