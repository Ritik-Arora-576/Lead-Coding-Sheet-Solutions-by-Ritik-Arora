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
// TC: O(N)
// SC: O(1)

class Solution {
    bool check(TreeNode* &root,TreeNode* &root1)
    {
        if(root==NULL and root1==NULL) return true;
        if(root==NULL or root1==NULL or root->val!=root1->val) return false;
        return check(root->left,root1->right) and check(root->right,root1->left);
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* root1=root;
        return check(root,root1);
    }
};