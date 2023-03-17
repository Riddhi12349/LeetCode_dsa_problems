/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
     ListNode* prv = NULL;
     ListNode* p = node;
     ListNode* t = p->next;
     while(t != NULL){
         p->val = t->val;
         prv = p;
         p = p->next;
         t = t->next;
     }   
     delete prv->next;
     prv->next = NULL;
    }
};