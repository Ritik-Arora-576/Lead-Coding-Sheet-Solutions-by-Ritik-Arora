// TC: O(m+n)
// SC: O(1)
// In place Algo

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // initializes pointer 'k' with the last index of nums1
        int k=m+n-1;
        int i=m-1;
        int j=n-1;
        
        // overwrite the larger element between nums1 and nums2 at the index 'k'
        while(j>=0)
        {
            if(i>=0 and nums1[i]>nums2[j]) nums1[k--]=nums1[i--];
            else nums1[k--]=nums2[j--];
        }
    }
};