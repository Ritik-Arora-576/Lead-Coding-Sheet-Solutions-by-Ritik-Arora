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
    int solve(TreeNode* &root,int &dia)
    {
        if(root==NULL) return 0;
        
        int left=solve(root->left,dia);
        int right=solve(root->right,dia);
        
        dia=max(dia,left+right+1);
        
        return max(left,right)+1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        solve(root,dia);
        return dia-1;
    }
};