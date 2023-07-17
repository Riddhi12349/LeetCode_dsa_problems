
class Solution {
public:
  
    ListNode* reverse(ListNode* h){
      
      if(h == NULL || h->next == NULL){
        return h;
      }

      ListNode* prv = NULL;
      ListNode* cur = h;
      ListNode* nxt = cur->next;
     
      while(cur != NULL){
        nxt = cur->next;
        cur->next = prv;
        prv = cur;
        cur = nxt;
      }

      return prv;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      /*
        3->4->2->7
        4->6->5
    +=   7->0->8->7
        7->8->0->7
        */

       ListNode* h1 = reverse(l1); 
       ListNode*h2 = reverse(l2);
       
      ListNode* dummy = new ListNode(0);
      dummy->next = NULL;
      ListNode* temp = dummy;

      int carry = 0;

      while(h1!=NULL || h2!= NULL){
          
          int a = h1!= NULL ? h1->val : 0;
          int b = h2!= NULL ? h2->val : 0;
          int sum = a+b+carry;
           carry = sum/10;
          ListNode* newNode = new ListNode(sum%10);
          temp->next = newNode;
          temp = temp->next;

          h1 =  h1 != NULL ? h1->next : NULL;
          h2 = h2 != NULL ? h2->next : NULL; 
      }
      if(carry != 0){
        ListNode* newNode = new ListNode(carry);
        temp->next = newNode;
      }
       dummy->next = reverse(dummy->next);
       return dummy->next;
    }
};