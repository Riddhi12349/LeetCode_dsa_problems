class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        
        TreeNode* cur = root;
        
        while(cur != NULL){
            
            if(cur->left != NULL){
                
                TreeNode* leftChild = cur->left;
                while(leftChild->right != NULL){
                    leftChild = leftChild->right;
                }
                
                leftChild->right = cur;
                
                TreeNode* tmp = cur;
                cur = cur->left;
                tmp->left = NULL;
                
            }
            
            else{
                ans.push_back(cur->val);
                cur = cur->right;
            }
                
        }
        
        return ans;
    }
};