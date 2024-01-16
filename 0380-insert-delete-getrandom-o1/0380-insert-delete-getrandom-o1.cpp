class RandomizedSet {
public:
    unordered_map <int,int> mp;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(mp.count(val)>0) return false;
        mp[val]++;
        return true;
    }
    
    bool remove(int val) {
        
        if(mp.count(val) == 0)
            return false;
        mp[val]--;
        if(mp[val]==0)
            mp.erase(val);
        return true;
    }
    
    int getRandom() {
       
        auto it = mp.begin();
        advance(it , rand() % mp.size());
        int k = it->first;
        
        return k;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */