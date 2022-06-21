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
// SC: O(height)

class Solution {
    void rightView(vector<int> &ans,int &height,TreeNode* &root)
    {
        if(root==NULL) return;
        
        if(height==ans.size()) ans.push_back(root->val);
        else ans[height]=root->val;
        
        height++;
        rightView(ans,height,root->left);
        rightView(ans,height,root->right);
        height--;
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int h=0;
        rightView(ans,h,root);
        return ans;
    }
};