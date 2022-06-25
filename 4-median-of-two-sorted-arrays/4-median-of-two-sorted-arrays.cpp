class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int> v;
        int i=0;
        int j=0;
        
        while(i<m and j<n)
        {
            if(nums1[i]>nums2[j]) v.push_back(nums2[j++]);
            else v.push_back(nums1[i++]);
        }
        
        while(i<m) v.push_back(nums1[i++]);
        while(j<n) v.push_back(nums2[j++]);
        
        if(v.size()%2) return v[v.size()/2]*1.00000;
        return ((v[v.size()/2]*1.00000)+(v[(v.size()/2)-1]*1.00000))/2.00000;
    }
};