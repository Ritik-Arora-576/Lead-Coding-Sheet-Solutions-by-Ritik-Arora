// TC: O(m+n)
// SC: O(m+n)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int i=0;
        int j=0;
        
        while(i<m and j<n)
        {
            if(nums1[i]>nums2[j]) temp.push_back(nums2[j++]);
            else temp.push_back(nums1[i++]);
        }
        
        while(i<m) temp.push_back(nums1[i++]);
        while(j<n) temp.push_back(nums2[j++]);
        
        nums1=temp;
    }
};