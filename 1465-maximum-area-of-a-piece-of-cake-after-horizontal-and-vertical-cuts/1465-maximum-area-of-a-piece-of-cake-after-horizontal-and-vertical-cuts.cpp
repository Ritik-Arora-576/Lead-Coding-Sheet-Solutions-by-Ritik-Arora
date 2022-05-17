// TC: O(NlogN)
// SC: O(1)

#define mod 1000000007

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        long long int a=0;
        
        for(int i=0;i<horizontalCuts.size()-1;i++) a=max(int(a),horizontalCuts[i+1]-horizontalCuts[i]);
        
        long long int b=0;
        
        for(int i=0;i<verticalCuts.size()-1;i++) b=max(int(b),verticalCuts[i+1]-verticalCuts[i]);
        
        return int((a%mod * b%mod)%mod);
    }
};