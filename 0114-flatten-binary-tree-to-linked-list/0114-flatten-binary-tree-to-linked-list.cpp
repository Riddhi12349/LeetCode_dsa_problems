class Solution {
public:
    void flatten(TreeNode* root) {
    
        TreeNode* cur = root;
        
        while(cur != NULL){
        
             if(cur->left != NULL){
                
                //CONNECT
                TreeNode* leftChild = cur->left;
                TreeNode* rtChild = cur->right;
                
                while(leftChild->right != NULL){
                    leftChild = leftChild->right;
                }
                leftChild->right = rtChild;
                
                 cur->right = cur->left;
                 TreeNode* tmp = cur->left;
                 cur->left = NULL;
                 
                 
                //MOVE
                cur = tmp;
                
            }
            else{
               cur = cur->right; 
            }
        }
        
       
        
    }
};