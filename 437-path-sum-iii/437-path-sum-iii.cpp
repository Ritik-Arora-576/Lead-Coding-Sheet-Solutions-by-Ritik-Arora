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
    void solve(TreeNode* &root,long &sum,int &targetSum,int &ans,unordered_map<long,int> &m)
    {
        if(root==NULL) return;
        sum+=long(root->val);
        if(m.find(sum-targetSum)!=m.end()) ans+=m[sum-targetSum];
        
        m[sum]++;
        
        solve(root->left,sum,targetSum,ans,m);
        solve(root->right,sum,targetSum,ans,m);
        
        m[sum]--;
        sum-=root->val;
    }
    
public:
    int pathSum(TreeNode* &root, int &targetSum) {
        unordered_map<long,int> m;
        long sum=0;
        m[0]=1;
        int ans=0;
        
        solve(root,sum,targetSum,ans,m);
        
        return ans;
    }
};