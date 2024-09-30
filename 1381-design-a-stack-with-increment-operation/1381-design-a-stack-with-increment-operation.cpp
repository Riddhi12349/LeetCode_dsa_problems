class CustomStack {
public:
    int curSize , totSize;
    vector<int> v1;
    
    CustomStack(int maxSize) {
        
        curSize = 0;
        totSize = maxSize; 
    }
    
    void push(int x) {
        
        if(curSize < totSize){
            v1.push_back(x);
            curSize++;
        }
        
    }
    
    int pop() {
        
        if(curSize == 0) return -1;
        
        curSize--;
        int val = v1.back();
        v1.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
      
        for(int i = 0 ; i < k  && i < curSize ; i++){
            v1[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */