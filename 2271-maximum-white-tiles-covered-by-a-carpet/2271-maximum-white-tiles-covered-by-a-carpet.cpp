class Solution {
    static bool compare(vector<int> &v1,vector<int> &v2) {return v1[0]<v2[0];}
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end(),compare);
        int ans=0;
        vector<int> v;
        for(auto data:tiles) v.push_back(data[0]);
        unordered_map<int,int> diff;
        diff[tiles[0][0]]=0;
        
        for(int i=1;i<tiles.size();i++) diff[tiles[i][0]]=diff[tiles[i-1][0]]+(tiles[i][0]-tiles[i-1][1]-1);
        
        for(int i=0;i<tiles.size();i++)
        {
            int data=tiles[i][0]+carpetLen-1;
            auto it=upper_bound(v.begin(),v.end(),data);
            it--;
            int idx=it-v.begin();
            int temp_ans=carpetLen;
            temp_ans-=(diff[v[idx]]-diff[v[i]]);
            // cout<<idx<<" "<<i<<endl;
            if(data>tiles[idx][1]) temp_ans-=(data-tiles[idx][1]);
            ans=max(ans,temp_ans);
        }
        
        // for(auto data:diff) cout<<data.first<<" "<<data.second<<endl;
        
        return ans;
    }
};