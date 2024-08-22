class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
       
        vector<int> ans;
        
        TreeNode* cur = root;
        
        while(cur != NULL){
            
            ans.push_back(cur->val);
            
            if(cur->left != NULL){
               
                //CONNECT
                TreeNode* leftChild = cur->left;
                TreeNode* rtChild = cur->right;
                
                while(leftChild->right != NULL){
                    leftChild = leftChild->right;
                }
                
                leftChild->right = rtChild;
                cur->right = NULL;
                //MOVE
                cur = cur->left;
            }
            else{
                cur = cur->right; 
            }
            
        }
        
        return ans;
    }
};