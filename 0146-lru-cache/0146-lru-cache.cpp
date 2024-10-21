class LRUCache {
public:
    unordered_map <int,list<int>::iterator> addrMp; // MAP-KEY-ADDRESS
    unordered_map <int,int> mp; //MAP-KEY-VALUE
    
    int curSize , totSize;
    list<int> li;
    
    LRUCache(int capacity) {
        
        curSize  = 0;
        totSize  = capacity;
    }
    
    int get(int key) {
        
        if(mp.count(key) == 0) return -1;
     
        auto addr = addrMp[key];
        li.erase(addr);
        addrMp.erase(key);
        
        li.push_back(key);
        addrMp[key] = --li.end();
        
        return mp[key];
    }
    
    void put(int key, int value) {
        
        if(mp.count(key) > 0){
            
            auto addr = addrMp[key];
            li.erase(addr);
            mp.erase(key);
            addrMp.erase(key);
            
            curSize--;
        }
        if(curSize == totSize){
            
            addrMp.erase(li.front());
            mp.erase(li.front());
            li.pop_front();
            
            curSize--;
        }
        
        li.push_back(key);
        addrMp[key]  = --li.end();
        mp[key] = value;
        
        curSize++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */