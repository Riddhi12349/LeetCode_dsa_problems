
class Solution {
public:
   // using p = pair<ListNode* , ListNode*>;
    
    class cmp{
      public:
        bool operator()(ListNode* l1 , ListNode* l2){
            return l1->val > l2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode* , vector<ListNode*> , cmp> pq;
        
        for(int i = 0 ; i < lists.size() ; i++){
           if(lists[i] != NULL){ pq.push(lists[i]); }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* tmp = dummy;
        
        while(!pq.empty()){
            
            ListNode* curr = pq.top();
            pq.pop();
            
            if(curr != NULL){
                tmp->next = new ListNode(curr->val);
                tmp = tmp->next;
            }
            
            if(curr != NULL && curr->next != NULL){
                pq.push(curr->next);
                curr = curr->next;
            }
            
        }
        
        tmp->next = NULL;
        return dummy->next;
    }
};