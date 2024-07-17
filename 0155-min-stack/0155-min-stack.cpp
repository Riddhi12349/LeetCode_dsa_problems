class MinStack {
public:
    //[-2 , 0 , -3, -5, -6, -8, -4, 2]
    
    stack<pair<int,int>> st;
    
    MinStack() {}
    
    void push(int val) {
        
        int tmp = st.empty() == true ? INT_MAX : st.top().second;
        st.push({val , min(val , tmp)}); 
    }
    
    void pop() {
        
        st.pop();
    }
    
    int top() {
        
        if(st.empty()) return -1;
        
        return st.top().first;
    }
    
    int getMin() {
        
        if(st.empty()) return -1;
        
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */