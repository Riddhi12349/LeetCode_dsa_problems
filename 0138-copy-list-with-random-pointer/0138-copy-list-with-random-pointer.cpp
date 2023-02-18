/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* helperf(Node* head){
        if(head == NULL){
            return NULL;
        }

    Node* newHead = new Node(head->val);
    newHead->next = helperf(head->next);
    return newHead;
    }
    Node* copyRandomList(Node* head) {
        
            Node* newHead = helperf(head);
            Node* p = head;
            Node* q = newHead;
            int cnt = 0;
            while(p != NULL){
                Node* t1 = p->random;
                Node* k = head;
                cnt = 0;
                while(k != t1){
                    cnt++;
                    k = k->next;
                }
                Node* t2 = newHead;
                if(t1 != NULL){
                    while(cnt != 0){
                        t2 = t2->next;
                        cnt--;
                    }
                q->random = t2;
                }

                else{
                    while(t2 != NULL){
                        t2 = t2->next;
                    }
                    q->random = t2;
                }
                q = q->next;
                p = p->next;
            }
            return newHead;
    }
};