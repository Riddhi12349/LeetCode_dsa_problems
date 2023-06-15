class Solution {
public:
    Node* copyRandomList(Node* head) {
       
        unordered_map<Node* , Node*> map;
        Node* p = head;
        Node *h = NULL;
        while(p != NULL){
            map[p] = new Node(p->val);
            if(h == NULL){
                h = map[p];
            }
            p = p->next;
        }
        p = head;
        while(p != NULL){
            map[p]->random = map[p->random];
            map[p]->next = map[p->next];
            p = p->next;
        }
    return h;
    }
};