// TC: O(1)
// SC: O(1)

class Solution {
    int dist(vector<int> &a,vector<int> &b){return ((b[0]-a[0])*(b[0]-a[0]))+((b[1]-a[1])*(b[1]-a[1]));}
    
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> s;
        if(p1!=p2) s.insert(dist(p1,p2));
        else return false;
        if(p1!=p3) s.insert(dist(p1,p3));
        else return false;
        if(p1!=p4) s.insert(dist(p1,p4));
        else return false;
        if(p2!=p3) s.insert(dist(p2,p3));
        else return false;
        if(p2!=p4) s.insert(dist(p2,p4));
        else return false;
        if(p3!=p4) s.insert(dist(p3,p4));
        else return false;
        
        return s.size()==2;
    }
};