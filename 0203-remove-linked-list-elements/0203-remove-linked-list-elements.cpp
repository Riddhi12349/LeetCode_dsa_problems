/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* p = head , *prv = NULL;
        while(p != NULL){
           
            if(p->val == val){
                ListNode* temp = p;
                
                if(prv != NULL){
                prv->next = p->next;
                }
                if(prv == NULL){
                    head = p->next;
                }
                
                p = p->next;
                 delete temp;
            }
            else{
             prv = p;
             p = p->next;
            }
        }
    
        return head;
    }
};