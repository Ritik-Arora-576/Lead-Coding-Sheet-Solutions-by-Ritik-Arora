// TC: O(nums1.size() + nums2.size())
// SC: O(nums2.size())

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        stack<int> s;
        
        for(int i=0;i<nums2.size();i++)
        {
            m[nums2[i]]=i;

            while(!s.empty() and nums2[i]>nums2[s.top()])
            {
                nums2[s.top()]=nums2[i];
                s.pop();
            }
            
            s.push(i);
        }
        
        while(!s.empty())
        {
            nums2[s.top()]=-1;
            s.pop();
        }
        
        for(int i=0;i<nums1.size();i++) nums1[i]=nums2[m[nums1[i]]];
        
        return nums1;
    }
};