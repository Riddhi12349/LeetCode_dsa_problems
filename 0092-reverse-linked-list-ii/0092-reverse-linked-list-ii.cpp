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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head == NULL || head->next == NULL || 
           left == right)
                    return head;
        
     //   1->2 NULL<-3<-4<-5
            
        int cnt = 1;
        
        ListNode* l = head, *r = head , *prev = NULL;
        
        while(cnt != left){    
            prev = l;
            l = l->next;
            cnt++;
        }
        
     ListNode* cur = l , *prv = NULL , *nxt = cur->next;
       //  null<-5<-1<-2<-3<-4
          
             cnt = 0;
          while(cnt != right){
              r = r->next;
              cnt++;
          } 
         prv = r;
        
          while(cur != r){  
            cur->next = prv;
            prv = cur;
            cur = nxt;
           if(nxt != NULL)  nxt = nxt->next;
        }
        
       
       //   l->next = cur;
        
        if(prev != NULL)
             prev->next = prv;
        else
            return prv;
        
        
        return head;
    }
};