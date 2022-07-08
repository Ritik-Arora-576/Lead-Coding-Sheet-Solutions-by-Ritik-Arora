// TC: O(nums2.size())
// SC: O(nums2.size())

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums2) {
        stack<int> s;
        
        for(int i=0;i<nums2.size();i++)
        {
            while(!s.empty() and nums2[i]>nums2[s.top()])
            {
                nums2[s.top()]=i-s.top();
                s.pop();
            }
            
            s.push(i);
        }
        
        while(!s.empty())
        {
            nums2[s.top()]=0;
            s.pop();
        }
        
        return nums2;
    }
};