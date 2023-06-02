
class Solution {
public:
    TreeNode* prv = NULL;
    void flatten(TreeNode* root) {
        
        if(root == NULL){
            return;
        }

        flatten(root->right);
        flatten(root->left);

        root->right = prv;
        root->left = NULL;
        prv = root;
    }
};