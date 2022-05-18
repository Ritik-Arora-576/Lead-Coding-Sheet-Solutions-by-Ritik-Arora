// TC: O(N^3)
// SC: O(N)

#define ll long long int

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        
        for(int a=0;a<n-3;a++)
        {
            if(a>0 and nums[a]==nums[a-1]) continue;
            
            for(int b=a+1;b<n-2;b++)
            {
                if(b>a+1 and nums[b]==nums[b-1]) continue;
                int i=b+1;
                int j=n-1;
                
                while(j>i)
                {
                    ll sum=0;
                    sum+=nums[a];
                    sum+=nums[b];
                    sum+=nums[i];
                    sum+=nums[j];
                    
                    if(sum>target) j--;
                    else if(sum<target) i++;
                    else
                    {
                        vector<int> temp={nums[a],nums[b],nums[i],nums[j]};
                        if(ans.size()==0 or (ans.size()>0 and ans[ans.size()-1]!=temp)) ans.push_back(temp);
                        i++;
                        j--;
                    }
                }
            }
        }
        
        return ans;
    }
};