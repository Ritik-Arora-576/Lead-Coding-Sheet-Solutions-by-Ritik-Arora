// TC: O(qlogn)
// SC: O(n)
// Segment Tree Approach

class NumArray {
    int tree[200000];
    int n;
    
    void buildTree(vector<int> &nums,int s,int e,int k)
    {
        if(s==e)
        {
            tree[k]=nums[s];
            return;
        }
        
        int mid=(s+e)/2;
        
        buildTree(nums,s,mid,2*k+1);
        buildTree(nums,mid+1,e,2*k+2);
        
        tree[k]=tree[2*k+1]+tree[2*k+2];
    }
    
    int findSum(int s,int e,int &l,int &r,int k)
    {
        // if the range is fully overlapping
        if(s>=l and e<=r) return tree[k];
        // if range is not overlapping at all
        if(s>r or e<l) return 0;
        // if the range is partially gets overlap then it would make a call on right as well as on left node
        int mid=(s+e)/2;
        return findSum(s,mid,l,r,2*k+1)+findSum(mid+1,e,l,r,2*k+2);
    }
    
    void updateSum(int s,int e,int &idx,int &val,int k)
    {
        if(s==e)
        {
            tree[k]=val;
            return;
        }
        
        int mid=(s+e)/2;
        
        if(idx<=mid) updateSum(s,mid,idx,val,2*k+1);
        else updateSum(mid+1,e,idx,val,2*k+2);
        
        tree[k]=tree[2*k+1]+tree[2*k+2];
    }
    
public:
    NumArray(vector<int>& nums) {
        this->n=nums.size()-1;
        buildTree(nums,0,nums.size()-1,0);
        //for(int data:tree) cout<<data<<" ";
    }
    
    void update(int index, int val) {
        updateSum(0,n,index,val,0);
    }
    
    int sumRange(int left, int right) {
        return findSum(0,n,left,right,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */