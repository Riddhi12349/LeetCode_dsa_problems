class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        int len = 0;
        
        ListNode* p = head;
        while(p != NULL){ len++; p = p->next; }
        
        int m = (len/2);
        p = head;
        
        while(m > 0){
            p = p->next;
            m--;
        }
        return p;
    }
};