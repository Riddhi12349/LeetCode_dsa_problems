class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *prv = head;
        ListNode *cur = head->next;
        while(cur != NULL){
            if(cur->val == prv->val){
                ListNode* temp = cur;
                prv->next = cur->next;
                cur = cur->next;
                delete temp;
            }
            else{
                prv = cur;
                cur = cur->next;
            }
        }

        return head;
    }
};