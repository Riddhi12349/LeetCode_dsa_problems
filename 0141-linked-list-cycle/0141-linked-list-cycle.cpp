class Solution {
public:
    bool hasCycle(ListNode *head) {
   
        ListNode* slow = head , *fast = head;
        
        while(slow != NULL && fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            if(fast->next != NULL)
                fast = fast->next->next;
            
            if(slow == fast)
                return true;
        }
        
        return false;
    }
};