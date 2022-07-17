// TC: O(nlogn)
// SC: O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q;
        vector<int> v;
        
        for(int i=0;i<k;i++) q.push(make_pair(nums[i],i));
        v.push_back(q.top().first);
        
        for(int i=k;i<nums.size();i++)
        {
            while(!q.empty() and q.top().second<=i-k) q.pop();
            q.push(make_pair(nums[i],i));
            v.push_back(q.top().first);
        }
        
        return v;
    }
};