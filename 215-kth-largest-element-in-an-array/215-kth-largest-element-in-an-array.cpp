// TC: O(nlogn)
// SC: O(n)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int data:nums)
        {
            if(pq.size()<k) pq.push(data);
            else if(pq.top()<data)
            {
                pq.pop();
                pq.push(data);
            }
        }
        
        return pq.top();
    }
};