class MyStack {
public:

    queue<int> q1;

    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        for(int i = 1 ; i <= q1.size()-1; i++){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        int ans = q1.front();
        return ans;
    }
    
    bool empty() {
        return q1.empty()==true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */