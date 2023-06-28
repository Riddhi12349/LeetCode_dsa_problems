class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = NULL;
        ListNode* temp = dummy;

        ListNode* p = head , *q = head->next;
    
        while(p != NULL){
            int f = 0;
           while(q != NULL && q->val == p->val){
               f= 1;
               q = q->next;
           }
           if(f== 0){
               temp->next = p;
               temp = temp->next;
           }
            p = q;
       if(q != NULL)     q = q->next;
        }

        temp->next = NULL;
        return dummy->next;
    }
};