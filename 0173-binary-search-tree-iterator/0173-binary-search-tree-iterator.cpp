class BSTIterator {
public:
    stack <TreeNode*> st;
    
    void pushAll(TreeNode* root){
        
        while(root != NULL){
            st.push(root);
            root = root->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
        
        pushAll(root);
    }
    
    int next() {
       
      if(!st.empty()){
        int value = st.top()->val;
        
        TreeNode* p = st.top();
        st.pop();
          
        pushAll(p->right); 
        
       // st.pop();
        return value;
      }
        return -1;
    }
    
    bool hasNext() {
        
        if(!st.empty()) return true;
        return false;
    }
};
