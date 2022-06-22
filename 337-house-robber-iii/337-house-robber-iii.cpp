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
    pair<int,int> solve(TreeNode* &root)
    {
        if(root==NULL)
        {
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        
        pair<int,int> p1=solve(root->left);
        pair<int,int> p2=solve(root->right);
        
        pair<int,int> p3=make_pair(max(p1.first+p2.first,root->val+p1.second+p2.second),p1.first+p2.first);
        
        return p3;
    }
    
public:
    int rob(TreeNode* root) {
        return solve(root).first;
    }
};