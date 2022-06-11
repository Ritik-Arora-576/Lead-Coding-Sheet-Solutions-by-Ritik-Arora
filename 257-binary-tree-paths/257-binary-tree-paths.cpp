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
class Solution {
    void store(TreeNode* &root,vector<int> &v,vector<string> &ans)
    {
        if(root==NULL) return;
        
        if(root->left==NULL and root->right==NULL)
        {
            string str="";
            for(int data:v) str+=to_string(data)+"->";
            str+=to_string(root->val);
            ans.push_back(str);
            return;
        }
        
        v.push_back(root->val);
        store(root->left,v,ans);
        store(root->right,v,ans);
        v.pop_back();
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> v;
        vector<string> ans;
        store(root,v,ans);
        return ans;
    }
};