class Solution {
public:
    TreeNode* find(TreeNode* root , int val){
        
        if(root == NULL) return NULL;
        
        if(root->val == val) return root;
        
        if(root->val > val){
            return find(root->left , val);
        }
        else{
            return find(root->right , val);
        }
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        
            return find(root, val);
    }
};