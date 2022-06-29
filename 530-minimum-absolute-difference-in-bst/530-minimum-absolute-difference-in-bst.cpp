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
    void solve(TreeNode* &root,int &prev,int &ans)
    {
        if(root==NULL) return;
        solve(root->left,prev,ans);
        ans=min(ans,abs(prev-root->val));
        prev=root->val;
        solve(root->right,prev,ans);
    }
    
public:
    int getMinimumDifference(TreeNode* root) {
        int prev=INT_MAX;
        int ans=INT_MAX;
        solve(root,prev,ans);
        return ans;
    }
};