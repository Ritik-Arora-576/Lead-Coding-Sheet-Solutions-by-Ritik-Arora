// Backtracking Solution

class Solution {
    void store(vector<vector<int>> &ans,vector<int> &temp,vector<vector<int>>& graph, int src)
    {
        if(src==graph.size()-1)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int data:graph[src])
        {
            temp.push_back(data);
            store(ans,temp,graph,data);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        vector<vector<int>> ans;
        temp.push_back(0);
        store(ans,temp,graph,0);
        return ans;
    }
};