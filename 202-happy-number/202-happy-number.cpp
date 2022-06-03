class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        
        while(true)
        {
            if(s.find(n)==s.end()) s.insert(n);
            else break;
            
            int data=0;
            
            while(n)
            {
                data+=(n%10)*(n%10);
                n/=10;
            }
            
            if(data==1) return true;
            
            n=data;
        }
        
        return false;
    }
};