class MinStack {
public:
  priority_queue<int , vector<int> , greater<int>> pq;
  ListNode *head ;
    MinStack() {
      head = new ListNode(0);
    }
    
    void push(int val) {
   
        pq.push(val);

        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }
    
    void pop() {

       ListNode* temp = head;
       int x = temp->val;
       head = head->next;
       delete temp; 
     
     priority_queue<int, vector<int> , greater<int>> pq2;
     int f = 0;
     while(!pq.empty()){
         int y = pq.top();
         if(y != x || f == 1){
             pq2.push(y);
             pq.pop();
         }
         else{
             pq.pop();
             f = 1;
         }
     }
     pq = pq2;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return pq.top();  
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