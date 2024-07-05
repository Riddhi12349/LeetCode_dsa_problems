class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        if(head->next->next == NULL) { return {-1,-1}; }
        
        vector<int> v1;
        
        ListNode* cur = head , *prv = head;
        cur = cur->next;
        
        int i = 2;
        while(cur->next != NULL){
            
            ListNode* nxt = cur->next;
            
            //detecting local minima
          if(prv->val > cur->val && cur->val < nxt->val){
                v1.push_back(i);
          }
            
            //detecting local maxima
          else if(prv->val < cur->val && cur->val > nxt->val){
                v1.push_back(i);      
          }
            
            i++;
            prv = cur;
            cur = cur->next;
        }
        
        if(v1.size()<2) return {-1,-1};
        
        int mx = v1.back()-v1[0];
        int mn = mx;
        
        for(int i = 0 ; i < v1.size()-1 ; i++){
            mn = min(mn , v1[i+1]-v1[i]);
        }
    
        return {mn , mx};
        
    }
};