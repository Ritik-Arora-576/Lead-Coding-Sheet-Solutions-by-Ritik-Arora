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

// TC: O(n)
// SC: O(n)

class Solution {
    class node{
        public:
        bool status;
        int maximum;
        int minimum;
        
        node(bool status,int maximum,int minimum)
        {
            this->status=status;
            this->minimum=minimum;
            this->maximum=maximum;
        }
    };
    
    node solve(TreeNode* &root)
    {   
        if(root->left==NULL and root->right==NULL)
        {
            node n(true,root->val,root->val);
            return n;
        }
        
        if(root->left==NULL)
        {
            node right=solve(root->right);
            if(!right.status or root->val>=right.minimum)
            {
                right.status=false;
                return right;
            }
            right.minimum=root->val;
            return right;
        }
        
        if(root->right==NULL)
        {
            node left=solve(root->left);
            if(!left.status or root->val<=left.maximum)
            {
                left.status=false;
                return left;
            }
            left.maximum=root->val;
            return left;
        }
        
        node right=solve(root->right);
        node left=solve(root->left);
        
        if(!right.status or !left.status or root->val<=left.maximum or root->val>=right.minimum)
        {
            right.status=false;
            return right;
        }
        
        node n(true,right.maximum,left.minimum);
        return n;
    }
    
public:
    bool isValidBST(TreeNode* &root) {
        return solve(root).status;
    }
};