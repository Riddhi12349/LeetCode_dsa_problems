class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* cur = head , *nxt = head->next;
        
        while(nxt != NULL){
          
            int gcd = __gcd(cur->val ,  nxt->val);
            ListNode* newNode = new ListNode(gcd);
            cur->next = newNode;
            newNode->next = nxt;
            
            cur = nxt;
            nxt = cur->next;
        }
        
        return head;
    }
};