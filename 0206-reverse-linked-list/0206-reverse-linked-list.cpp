class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;

        ListNode *prv = NULL , *cur = head , *nxt = head->next;

        while(cur != NULL){
            cur->next = prv;
            prv = cur;
            cur = nxt;
            if(nxt != NULL) nxt = nxt->next;
        }

        return prv;
    }           
};