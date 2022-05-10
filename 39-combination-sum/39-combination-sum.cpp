// Backtraking Solution

class Solution {
    void store(vector<vector<int>> &ans,vector<int>& candidates,int target,int i,vector<int> &temp)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(i==candidates.size() or target<0) return;
        
        temp.push_back(candidates[i]);
        store(ans,candidates,target-candidates[i],i,temp);
        temp.pop_back();
        store(ans,candidates,target,i+1,temp);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        store(ans,candidates,target,0,temp);
        return ans;
    }
};