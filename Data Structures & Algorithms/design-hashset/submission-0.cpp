class MyHashSet {
    private:
    unordered_map<int,int> set;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        set.insert({key,1});
    }
    
    void remove(int key) {
        set.erase(key);
        
    }
    
    bool contains(int key) {
        return set.find(key) != set.end();
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */