// Sorting wrt ending point
// TC: O(nlogn)
// SC: O(1)

class Solution {
    static bool compare(vector<int> &v1,vector<int> &v2)
    {
        return v1[1]<v2[1];
    }
    
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int count=0;
        int last=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<last) count++;
            else last=intervals[i][1];
        }
        
        return count;
    }
};