class MyCircularDeque {
public:
    vector<int> v1;
    int top , last , curSize , totSize;
    
    void pushFront(int val){
        
        vector<int> tmp;
        
        tmp.push_back(val);

        for(auto x : v1){
            tmp.push_back(x);
        }
        
        v1 = tmp;
    }
    
    void popFront(){
        
        vector<int> tmp;
        
        for(int i = 1 ; i < curSize ; i++){
            tmp.push_back(v1[i]);
        }
        
        v1 = tmp;
        
    }
    
    MyCircularDeque(int k) {
     
        curSize = 0;
        totSize = k;
    }
    
    bool insertFront(int value) {
        
        if(curSize == totSize) return false;
        
        if(curSize == 0){
            v1.push_back(value);
        }
        else{
            pushFront(value);
        }
        curSize++;
        return true;
    }
    
    bool insertLast(int value) {
        
        if(curSize == totSize) return false;
        
        v1.push_back(value);
      
        curSize++;
        return true;
    }
    
    bool deleteFront() {
        
        if(curSize > 0){
           
            popFront();
            curSize--;
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        
     if(curSize == 0) return false;
        
          v1.pop_back();
          curSize--;
       
        return true;
    }
    
    int getFront() {
        
        return curSize > 0 ? v1[0] : -1;
    }
    
    int getRear() {
        
        return curSize > 0 ? v1.back() : -1;
    }
    
    bool isEmpty() {
        return curSize==0;
    }
    
    bool isFull() {
        return curSize == totSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */