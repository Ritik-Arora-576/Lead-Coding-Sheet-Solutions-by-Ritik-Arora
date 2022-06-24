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
    pair<bool,int> solve(TreeNode* &root)
    {
        if(root==NULL) return make_pair(true,0);
        
        pair<bool,int> p1=solve(root->left);
        if(!p1.first) return make_pair(false,0);
        pair<bool,int> p2=solve(root->right);
        if(!p2.first) return make_pair(false,0);
        
        if(abs(p2.second-p1.second)>1) return make_pair(false,0);
        
        return make_pair(true,max(p1.second,p2.second)+1);
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};