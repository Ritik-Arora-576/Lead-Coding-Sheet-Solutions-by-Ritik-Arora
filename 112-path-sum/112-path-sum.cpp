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
    bool solve(TreeNode* &root, int targetSum)
    {
        if(root==NULL) return false;
        if(root->left==NULL and root->right==NULL) return targetSum==root->val?true:false;
        return solve(root->left,targetSum-root->val) or solve(root->right,targetSum-root->val);
    }
    
public:
    bool hasPathSum(TreeNode* &root, int &targetSum) {
        if(root==NULL) return false;
        return solve(root,targetSum);
    }
};