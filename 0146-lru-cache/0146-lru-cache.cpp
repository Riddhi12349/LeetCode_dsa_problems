class LRUCache {
public:
    int size;
    int cursize;

    unordered_map<int,int> mp;
    unordered_map<int,list<int>::iterator> address;
    
    list<int> l;

    LRUCache(int capacity) {
        size = capacity;
        cursize = 0;
    }
    
    int get(int key) {

        if(mp.find(key) == mp.end()) return -1;

        l.erase(address[key]);  
        l.push_front(key);
        address.erase(key);
        address[key] = l.begin();
        return mp[key];
    }
    
    void put(int key, int value) {
        
        // only keeping unique values in the cache --
        if(mp.find(key) != mp.end()){
            mp.erase(key);
            l.erase(address[key]);
            address.erase(key);
            cursize--;
        }
        if(cursize == size){
          // delete last node of the cache       
          int k = l.back();
          mp.erase(k);
          address.erase(k);
          l.pop_back();
          cursize--;
        }
        l.push_front(key);
        address[key] = l.begin();
        mp[key] = value;
        cursize++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */