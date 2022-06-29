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
// SC: O(N)

class Solution {
    int solve(TreeNode* &root,bool status)
    {
        if(root==NULL) return 0;
        if(root->left==NULL and root->right==NULL and status) return root->val;
        if(root->left==NULL and root->right==NULL and !status) return 0;
        return solve(root->left,true)+solve(root->right,false);
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,false);
    }
};