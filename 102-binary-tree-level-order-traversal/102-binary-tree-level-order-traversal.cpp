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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        
        while(!q.empty())
        {
            TreeNode* temp=q.front().first;
            int depth=q.front().second;
            q.pop();
            
            if(depth==ans.size())
            {
                vector<int> v={temp->val};
                ans.push_back(v);
            }
            
            else ans[ans.size()-1].push_back(temp->val);
            
            if(temp->left) q.push(make_pair(temp->left,depth+1));
            if(temp->right) q.push(make_pair(temp->right,depth+1));
        }
        
        return ans;
    }
};