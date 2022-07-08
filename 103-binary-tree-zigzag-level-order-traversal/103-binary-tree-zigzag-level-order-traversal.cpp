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
    void reverse(vector<int> &temp)
    {
        int i=0,j=temp.size()-1;
        while(j>i) swap(temp[i++],temp[j--]);
    }
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        int max=0;
        vector<int> temp;
        
        while(!q.empty())
        {
            TreeNode* node=q.front().first;
            int level=q.front().second;
            
            if(level>max)
            {
                if(max&1) reverse(temp);
                ans.push_back(temp);
                temp={};
                max=level;
            }
            
            temp.push_back(node->val);
            q.pop();
            
            if(node->left) q.push(make_pair(node->left,level+1));
            if(node->right) q.push(make_pair(node->right,level+1));
        }
        
        if(max&1) reverse(temp);
        ans.push_back(temp);
        
        return ans;
    }
};