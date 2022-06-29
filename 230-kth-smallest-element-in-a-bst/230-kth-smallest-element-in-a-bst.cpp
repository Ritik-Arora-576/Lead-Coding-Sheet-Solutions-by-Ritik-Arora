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
    void store(TreeNode* &root, int &ans, int &k)
    {
        if(root==NULL) return;
        
        store(root->left,ans,k);
        k--;
        if(k==0) ans=root->val;
        store(root->right,ans,k);
    }
    
public:
    int kthSmallest(TreeNode* &root, int k) {
        int ans=-1;
        store(root,ans,k);
        return ans;
    }
};