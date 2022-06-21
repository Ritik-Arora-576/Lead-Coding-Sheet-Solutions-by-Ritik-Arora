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
// SC: O(N)

class Solution {
    bool iterate(TreeNode* &root, TreeNode* &p, TreeNode* &q,TreeNode* &ans)
    {
        if(root==NULL) return false;
        if(root->val==p->val or root->val==q->val)
        {
            ans=root;
            return true;
        }
        
        bool left=iterate(root->left,p,q,ans);
        bool right=iterate(root->right,p,q,ans);
        
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
        iterate(root,p,q,ans);
        return ans;
    }
};