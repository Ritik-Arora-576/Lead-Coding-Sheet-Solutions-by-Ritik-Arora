// TC: O(N)
// SC: O(N)

class StockSpanner {
    stack<pair<int,int>> s;
    int i;
public:
    StockSpanner() {
        this->i=0;
    }
    
    int next(int price) {
        while(!s.empty() and s.top().first<=price) s.pop();
        int ans=0;
        if(s.empty()) ans=i+1;
        else ans=i-s.top().second;
        s.push(make_pair(price,i));
        i++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */