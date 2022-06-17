/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> m;
        for(auto data:employees) m[data->id]=data;
        
        int ans=0;
        
        queue<Employee*> q;
        q.push(m[id]);
        
        while(!q.empty())
        {
            Employee* e=q.front();
            ans+=e->importance;
            q.pop();
            
            for(auto data:e->subordinates)
                q.push(m[data]);
        }
        
        return ans;
    }
};