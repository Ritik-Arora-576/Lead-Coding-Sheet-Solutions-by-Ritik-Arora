class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // firstly, check if 1 present or not
        bool status=false;
        for(int data:nums) if(data==1) status=true;
        
        // if 1 is present then mark the element which is out of range i.e Range=[1,n] to 1
        // otherwise it's obvious that our answer should be 1 if 1 is not present
        if(!status) return 1;
        
        for(int i=0;i<nums.size();i++)
            if(nums[i]<1 or nums[i]>nums.size()) nums[i]=1;
        
        // now every element is within range [1,n] and mark (abs(nums[i])-1)th element to negetive if not 
        for(int i=0;i<nums.size();i++)
            if(nums[abs(nums[i])-1]>0) nums[abs(nums[i])-1]*=-1;
        
        // now check which position is positive that would be an answer otherwise n+1 would be an answer
        for(int i=0;i<nums.size();i++) if(nums[i]>0) return i+1;
        
        return nums.size()+1;
    }
};
