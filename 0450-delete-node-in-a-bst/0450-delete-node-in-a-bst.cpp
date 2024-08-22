class Solution {
public:
    int findMaxValue(TreeNode* root){
       
        while(root->right != NULL){
            root = root->right;
        }
        return root->val;
    }
    TreeNode* deleteNodeFromBST(TreeNode* root, int key){
        
        if(root == NULL) 
            return NULL;
        
        if(root->val == key){
            
            //DELETE 
            //CASE : 0 CHILD
            
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            
            //CASE-1: 1 LEFT CHILD
            else if(root->left != NULL && root->right == NULL){
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }
            
            //CASE-2: 1 RIGHT CHILD
           else if(root->left == NULL && root->right != NULL){
               TreeNode* tmp = root->right;
               delete root;
               return tmp;
           }
            
            //CASE-3: 1 LEFT AND 1 RIGHT CHILD
           else if(root->left != NULL && root->right != NULL){
               
               int mx = findMaxValue(root->left);
               root->val = mx;
               root->left = deleteNodeFromBST(root->left , mx);
               return root;
           } 
            
        }
        else if(root->val > key){
           root->left = deleteNodeFromBST(root->left , key);
        }
        else if(root->val < key){
           root->right = deleteNodeFromBST(root->right , key);
        }
        
        return root;
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        return deleteNodeFromBST(root , key);
    }
};