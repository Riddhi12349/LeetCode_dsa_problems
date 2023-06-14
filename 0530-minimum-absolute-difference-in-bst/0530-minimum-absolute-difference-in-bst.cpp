class Solution {
public:
    TreeNode* prv = NULL;

    void inorder(TreeNode* root , int& diff){

        if(root == NULL){
            return ;
        }
        inorder(root->left , diff);
        
        if(prv != NULL)
        diff = min(diff , abs(root->val - prv->val));

        prv = root;
        inorder(root->right , diff);
    }
    int getMinimumDifference(TreeNode* root) {
    
     int diff = INT_MAX;
      inorder(root , diff);
        return diff;

    }
};