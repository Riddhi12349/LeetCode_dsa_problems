class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
     ListNode* dummy = new ListNode(-1);
     ListNode* tmp = dummy;
        
     unordered_map<int,int> mp;
        
     while(head != NULL){
         
         if(mp.count(head->val)==0){
             tmp->next = new ListNode(head->val);
             tmp = tmp->next;
             mp[head->val]++;
         }
         head = head->next;
     }
        
     return dummy->next;
    }
};