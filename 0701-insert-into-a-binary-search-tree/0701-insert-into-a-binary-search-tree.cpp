class Solution {
public:
    void find(TreeNode* root  , TreeNode* prv , int x){
        
        if(root == NULL){
            
            TreeNode* newNode = new TreeNode(x);
            
            if(prv != NULL){
             
                if(x > prv->val){
                    prv->right = newNode;
                }
                else{
                    prv->left = newNode;
                }
              return;    
            }
            
        }
        if(root->val > x){
            find(root->left , root , x);
        }
        else{
            find(root->right , root , x);
        }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root == NULL){
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        
        find(root , NULL , val);
        return root;
    }
};