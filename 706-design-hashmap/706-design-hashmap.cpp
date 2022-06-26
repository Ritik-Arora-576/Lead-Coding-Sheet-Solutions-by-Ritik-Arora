// TC: O(N)
// SC: O(1000001)

class MyHashMap {
    vector<int> v;
public:
    MyHashMap() {
        vector<int> temp(1000001,-1);
        this->v=temp;
    }
    
    void put(int key, int value) {
        v[key]=value;
    }
    
    int get(int key) {
        return v[key];
    }
    
    void remove(int key) {
        v[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */