// Next Permutation
// TC: O(N)
// SC: O(N)

class Solution {
    void nextPermutation(string& nums) {
        bool flag=false;
        
        for(int i=nums.length()-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                flag=true;
                int j=i;
                
                while(j<nums.size() and nums[j]>nums[i-1])
                    j++;
                
                j--;
                
                swap(nums[j],nums[i-1]);
                
                int k=nums.size()-1;
                j=i;
                
                while(k>j)
                swap(nums[k--],nums[j++]);
                break;
            }
        }
        
        if(!flag)
        {
            int i=0;
            int j=nums.size()-1;
            while(j>i)
                swap(nums[j--],nums[i++]);
        }
    }
    
public:
    string getPermutation(int n, int k) {
        string str="";
        for(int i=1;i<=n;i++)
        {
            char ch='0'+i;
            str+=ch;
        }
        
        k--;
        while(k--) nextPermutation(str);
        
        return str;
    }
};