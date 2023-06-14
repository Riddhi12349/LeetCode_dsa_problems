class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* after = head;
        ListNode* before = dummy;
        while(1){
            ListNode* cursor = after;
            for(int i = 0 ; i < k ; i++){
                if(cursor == NULL){ return dummy->next; }
                cursor = cursor->next;
            }

            ListNode* cur = after;
            ListNode* prv = before;
            ListNode* nxt = cur->next;
            for(int i = 0 ; i < k ; i++){
                cur->next = prv;
                prv = cur;
                cur = nxt;
                if(nxt != NULL){ nxt = nxt->next; }
            }
            after->next = cur;
            before->next = prv; // new head
            before = after;
            after = cur;
        }
    }
};