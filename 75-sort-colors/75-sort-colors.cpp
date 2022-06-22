// TC: O(N)
// SC: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(3,0);
        int i=0;
        for(int data:nums) v[data]++;
        
        while(v[0]--) nums[i++]=0;
        while(v[1]--) nums[i++]=1;
        while(v[2]--) nums[i++]=2;
    }
};