// TC= O(N)
// SC= O(N)
// Hashmap Solution

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        for(int i=0;i<time.size();i++) time[i]%=60;
        int count=0;
        unordered_map<int,int> m;
        
        for(int data:time)
        {
            if(data==0 and m.find(0)!=m.end()) count+=m[0];
            
            else if(data!=0 and m.find(60-data)!=m.end()) count+=m[60-data];
            
            m[data]++;
        }
        
        return count;
    }
};