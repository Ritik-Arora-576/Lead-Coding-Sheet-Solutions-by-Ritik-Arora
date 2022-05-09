// Question Link: https://leetcode.com/problems/3sum/
// Sorting + Two Pointers approach
// Time Complexity: O(n^2)
// Space Complexity: O(n)

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        if(nums.size()<3) return ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i>0 and nums[i]==nums[i-1]) continue;
            
            int j=i+1;
            int k=nums.size()-1;
            
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    
                    if(ans.size()==0 or temp!=ans[ans.size()-1])
                        ans.push_back(temp);
                    
                    j++;
                    k--;
                }
                
                else if(nums[i]+nums[j]+nums[k]>0) k--;
                else j++;
            }
        }
        
        return ans;
    }