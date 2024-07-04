class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* t = head;
        ListNode* tmp = new ListNode(0);
        ListNode* nh = NULL;
        
        int s = 0;
        while(t != NULL){
            s += t->val;
          //  t = t->next;
            if(t->val == 0){
              ListNode* newNode = new ListNode(s);
              s = 0;
              tmp->next = newNode;
              tmp = tmp->next;
              if(nh == NULL) {nh = tmp;}
            }
            t = t->next;
        }
        
        return nh->next;
    }
};