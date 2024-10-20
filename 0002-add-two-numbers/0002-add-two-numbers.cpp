class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode(-1);
        ListNode* tmp = dummy;
        
        ListNode* h1 = l1 , *h2  = l2;
        
        int carry = 0;
        
        while(h1 != NULL || h2 != NULL || carry){
            
           int val1 = h1 != NULL ? h1->val : 0;
           int val2 = h2 != NULL ? h2->val : 0;
            
           int sum = val1 + val2 + carry;
           carry = sum/10;
            
           ListNode* newNode = new ListNode(sum % 10);
           
           tmp->next = newNode;
           tmp = tmp->next;
            
           h1 = h1 ? h1->next : NULL;
           h2 = h2 ? h2->next : NULL;
            
        }
        
        return dummy->next;
    }
};