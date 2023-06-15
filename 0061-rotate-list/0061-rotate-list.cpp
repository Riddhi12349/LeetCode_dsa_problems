class Solution {
public:

    // int length(ListNode* head){
    //     int cnt = 0;
    //     while(head != NULL){
    //         cnt++;
    //         head = head->next;
    //     }
    //     return cnt;
    // }
    
    ListNode* rotateRight(ListNode* head, int k) {
      
      if(k == 0 || head == NULL  || head->next == NULL){ return head; }
        //  int len = length(head);
        int len = 1;
      
        // stack<ListNode*> st;
        ListNode* p = head;
        while(p->next != NULL){
            // st.push(p);
            len++;
            p = p->next;
        }
        p->next = head;

        if(k >= len) { k = k%len;}
        for(int i = 0 ; i < len-k ; i++){
           p = p->next;
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};