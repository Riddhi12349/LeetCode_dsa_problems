class Solution {
public:
    
    TreeNode *prv  , *first , *middle , *last;
    
    void inorder(TreeNode* root){
        
        if(root == NULL) return;
        
        inorder(root->left);
        
        if(prv && root->val < prv->val){
            //VIOLATION
            
            if(first == NULL){
                first = prv;
                middle = root;
            }
            else{
                last = root;
            }
        }
        
        prv = root;
        
        inorder(root->right);
        
    }
    void recoverTree(TreeNode* root) {
        
        first = middle = last = NULL;
        prv = new TreeNode(INT_MIN);
        
        inorder(root);
        
        if(first && last){
            swap(first->val , last->val);
        }
        else{
            swap(first->val , middle->val);
        }
    }
};