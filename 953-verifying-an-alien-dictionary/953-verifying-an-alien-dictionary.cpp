// TC: O(N)
// SC: O(1)

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> v(26);
        
        for(int i=0;i<order.length();i++)
        {
            int idx=order[i]-'a';
            v[idx]=i;
        }
        
        // for(int data:v) cout<<data<<" ";
        
        for(int k=0;k<words.size()-1;k++)
        {
            int i=0;
            
            while(i<words[k].length())
            {
                if(i==words[k+1].length()) return false;
                
                int data1=v[words[k][i]-'a'];
                int data2=v[words[k+1][i]-'a'];
                
                if(data1>data2) return false;
                else if(data1<data2) break;
                
                i++;
            }
        }
        
        return true;
    }
};