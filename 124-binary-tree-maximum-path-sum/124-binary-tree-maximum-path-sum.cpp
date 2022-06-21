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
    int solve(TreeNode* &root,int &ans)
    {
        if(root==NULL) return 0;
        
        int leftSum=solve(root->left,ans);
        int rightSum=solve(root->right,ans);
        
        int sum=root->val+max(0,leftSum)+max(0,rightSum);
        ans=max(ans,sum);
        return max(0,max(leftSum,rightSum)+root->val);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};