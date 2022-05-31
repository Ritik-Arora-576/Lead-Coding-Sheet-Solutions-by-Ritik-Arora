// Priority Queue
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        for(char ch:tasks) v[ch-'A']++;
        priority_queue<int> q;
        for(int data: v) if(data) q.push(data);
        
        n++;
        int ans=0;
        
        while(true)
        {
            vector<int> temp;
            int x=0;
            
            for(int i=0;i<n;i++)
            {
                temp.push_back(q.top()-1);
                q.pop();
                x++;
                
                if(q.size()==0) break;
            }
            
            for(int data:temp) if(data) q.push(data);
            
            if(q.size()==0)
            {
                ans+=x;
                break;
            }
            
            else ans+=n;
        }
        
        return ans;
    }
};