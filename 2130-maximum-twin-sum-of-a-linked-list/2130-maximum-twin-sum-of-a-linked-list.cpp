class Solution {
public:
    int length(ListNode* head){
       
        ListNode* cur = head;
        int len = 0;
        
        while(cur != NULL){
            len++;
            cur = cur->next;
        }
        
        return len;
    }
    
    ListNode* reverse(ListNode* head , int len){
        
        int half = len/2;
        ListNode* cur = head;
        
        while(half > 0){
            cur = cur->next;
            half--;
        }
      
        ListNode* ptr = cur;
        ListNode* prv = NULL;
        
        while(ptr != NULL){
            ListNode* nxt = ptr->next;
            ptr->next = prv;
            prv = ptr;
            ptr = nxt;
        }
        
        return prv;
    }
    
    int pairSum(ListNode* head) {
        
        int len = length(head);
        
        ListNode* revHead = reverse(head , len);
        
        int sum = 0 , mxSum = 0;
        
        while(revHead != NULL){
            
            sum = head->val + revHead->val;
            head = head->next;
            revHead = revHead->next;
            
            mxSum = max(mxSum , sum);
        }
        
        return mxSum;
    }
};