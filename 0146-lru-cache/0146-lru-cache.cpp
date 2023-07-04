class LRUCache {
public:
    
    unordered_map<int,int> mp;
    unordered_map<int,list<int>::iterator> address;
    
    list<int> l; // doubly linked list
    
    int size;
    int cur_size;
    
    LRUCache(int capacity) {
        
        size = capacity;
        cur_size = 0;
    }
    
    int get(int key) {
        
        if(mp.find(key) == mp.end()) return -1;
        
   //     list<int>::iterator itr = address[key];
        l.erase(address[key]);
        address.erase(key);
        l.push_front(key);
        address[key] = l.begin();
        
        return mp[key];
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()){
            l.erase(address[key]);
            mp.erase(key);
            address.erase(key);
            cur_size--;
        }
        
        if(cur_size == size){
        // node to be removed will be present at the last   
            int k = l.back();
            l.pop_back();
            mp.erase(k);
            address.erase(k);
            cur_size--;
        }
        
        mp[key] = value;
        l.push_front(key);
        address[key] = l.begin();
        cur_size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */