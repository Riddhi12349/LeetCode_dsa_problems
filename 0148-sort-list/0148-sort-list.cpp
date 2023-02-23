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
   
    ListNode* merge2sortedLL(ListNode *h1 , ListNode *h2){

      if(h1 == NULL || h2 == NULL){
          return (h1 == NULL) ? h2 : h1;
      }
      ListNode* p = h1 , *q = h2;
      ListNode* ans = new ListNode(0);
      ListNode* curr = ans;
      while(p != NULL && q != NULL){
          if(p->val < q->val){
              curr->next = p;
              p = p->next;
          }
          else{
              curr->next = q;
              q = q->next;
          }
          curr = curr->next;
      }
      (p == NULL) ? curr->next = q : curr->next = p;
      return ans->next;
   }

   ListNode* midNode(ListNode* head){
       ListNode* slow = head, *fast = head;
   while(fast->next != NULL && fast->next->next != NULL){
       slow = slow->next;
       fast = fast->next->next;
   }
   return slow;
   }

    ListNode* MergeSort(ListNode* head) {
  
     if(head == NULL || head->next == NULL){
     return head;
    }

     
    ListNode* mid = midNode(head);
    ListNode* p = mid->next;
    mid->next = NULL;
     ListNode* fsh = MergeSort(head);
     ListNode* ssh = MergeSort(p);
     ListNode* h =  merge2sortedLL(fsh , ssh);
        return h;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
      
        return MergeSort(head);
    }
};