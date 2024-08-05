class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       
       unordered_map<int,int> mp;
        
       ListNode* ptr = head;
       
       while(ptr != NULL){
           mp[ptr->val]++;
           ptr = ptr->next;
       }
        
       ListNode* dummy = new ListNode(0);
       ListNode* tmp = dummy;
        
       while(head != NULL){
           if(mp[head->val] == 1){
               tmp->next = new ListNode(head->val);
               tmp = tmp->next;
           }
           head = head->next;
       }
        
        return dummy->next;
    }
};