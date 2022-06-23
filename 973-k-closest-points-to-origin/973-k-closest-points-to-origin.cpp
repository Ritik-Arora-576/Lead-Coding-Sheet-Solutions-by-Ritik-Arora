// TC: O(nlogn)
// SC: O(n)

class Solution {
    class store{
        public:
        
        float dist;
        int x;
        int y;
        
        store(float dist,int x,int y)
        {
            this->dist=dist;
            this->x=x;
            this->y=y;
        }
    };
    
    float calc(vector<int> points) {return sqrt(points[0]*points[0]+points[1]*points[1]);}
    
    struct compare  
     {  
       bool operator()(const store& s1, const store& s2)  
       {  
           return s1.dist < s2.dist;  
       }  
     }; 
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<store,vector<store>,compare> pq;
        
        for(auto point:points)
        {
            store s(calc(point),point[0],point[1]);
            if(pq.size()<k) pq.push(s);
            else if(pq.top().dist>s.dist)
            {
                pq.pop();
                pq.push(s);
            }
        }
        
        vector<vector<int>> ans;
        
        while(pq.size()) 
        {
            ans.push_back({pq.top().x,pq.top().y});
            pq.pop();
        }
        
        return ans;
    }
};