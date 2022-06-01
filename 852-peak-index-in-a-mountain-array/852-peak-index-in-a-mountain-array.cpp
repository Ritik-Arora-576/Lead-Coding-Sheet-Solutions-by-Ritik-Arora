// TC: O(logn)
// SC: O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=1;
        int e=arr.size()-2;
        
        while(e>=s)
        {
            int mid=(s+e)/2;
            if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1]) return mid;
            else if(arr[mid]>arr[mid-1]) s=mid+1;
            else e=mid-1;
        }
        
        return 0;
    }
};