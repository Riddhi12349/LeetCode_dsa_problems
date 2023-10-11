class MyHashMap {
public:
    
    int v1[1000002] ;
    
    MyHashMap(){
   // for(int i = 0 ; i <= 1e6 ; i++){
   //     v1[i] = -1;
   // }
        fill(v1 , v1+1000001 , -1);
    }
    
    void put(int key, int value) {
        v1[key] = value;
    }
    
    int get(int key) {
        int val = v1[key];
        return val;
    }
    
    void remove(int key) {
        v1[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */