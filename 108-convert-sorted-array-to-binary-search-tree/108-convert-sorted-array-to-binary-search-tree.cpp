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
    void buildBST(TreeNode* &root,vector<int>& nums,int s,int e)
    {
        if(s>e) return;
        
        if(s==e)
        {
            root=new TreeNode(nums[s]);
            return;
        }
        
        int mid=(s+e)/2;
        root=new TreeNode(nums[mid]);
        
        buildBST(root->left,nums,s,mid-1);
        buildBST(root->right,nums,mid+1,e);
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root=NULL;
        buildBST(root,nums,0,nums.size()-1);
        return root;
    }
};