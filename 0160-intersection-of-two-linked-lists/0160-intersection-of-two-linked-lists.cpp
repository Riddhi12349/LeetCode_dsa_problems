class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int cnt1 = 0 , cnt2 = 0;
        
        ListNode* p = headA;
        while(p != NULL){
            cnt1++; //6
            p = p->next;
        }

        ListNode* q = headB;
        while(q != NULL){
            cnt2++; //5
            q = q->next;
        }

        if(cnt1 > cnt2){
            while(cnt1 != cnt2){
                headA = headA->next;
                cnt1--;
            }
        }

        if(cnt2 > cnt1){
            while(cnt1 != cnt2){
                headB = headB->next;
                cnt2--;
            }
        }

        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};