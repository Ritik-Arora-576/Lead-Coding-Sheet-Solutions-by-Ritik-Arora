// TC: O(NlogN)
// SC: O(N)

class Solution {
    static bool compare(vector<int> &v1,vector<int> &v2) {return v1[0]<v2[0];}
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++)
        {
            if(ans[ans.size()-1][1]>=intervals[i][0]) ans[ans.size()-1][1]=max(ans[ans.size()-1][1],intervals[i][1]);
            else ans.push_back(intervals[i]);
        }
        
        return ans;
    }
};