class MyQueue {
public: 
   // q = [1,2,4,6,8,10] , st = [1,2,4] => []
        
    stack<int> st1 , st2;
    
    MyQueue() {}      
    
    void push(int x) {
        
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        
        st1.push(x);
        
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
           
    }
    
    int pop() {
      
        if(st1.empty()) return -1;
        
        int ans = st1.top();
        st1.pop();
        return ans;
    }
    
    int peek() {
        
        if(st1.empty()) return -1;
        
        return st1.top();
    }
    
    bool empty() {
        
        return st1.empty() == true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */