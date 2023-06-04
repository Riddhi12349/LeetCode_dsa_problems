class Solution {
public:
    Node* connect(Node* root) {
        Node* p = root;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* f = q.front();
            q.pop();
            if(f != NULL ){
            if(f->left != NULL)
                q.push(f->left);

            if(f->right != NULL)
                q.push(f->right);
            }
            if(f != NULL)
                 f->next = q.front();
            
            if(q.front() == NULL){
                    q.pop();
                    if(!q.empty()){ q.push(NULL); }
                }
           
        }
        return root;
    }
};