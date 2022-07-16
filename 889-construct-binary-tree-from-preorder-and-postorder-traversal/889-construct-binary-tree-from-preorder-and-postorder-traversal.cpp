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
    void build(TreeNode* &root, int &k, vector<int>& preorder, vector<int>& postorder, int s, int e)
    {
        int idx=-1;
        for(int i=s;i<=e;i++)
        {
            if(preorder[k]==postorder[i])
            {
                idx=i;
                break;
            }
        }
        
        if(idx==-1) return;
        k++;
        
        root=new TreeNode(preorder[k-1]);
        
        if(k==preorder.size()) return;
        
        int idx1=-1;
        
        for(int i=s;i<idx;i++)
        {
            if(preorder[k]==postorder[i])
            {
                idx1=i;
                break;
            }
        }
        
        build(root->left,k,preorder,postorder,s,idx1);
        build(root->right,k,preorder,postorder,idx1+1,e-1);
    }
    
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root=NULL;
        int i=0;
        build(root,i,preorder,postorder,0,preorder.size()-1);
        return root;
    }
};