class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(root == NULL){
            return NULL;
        }
        
        if(root->val == val)
        {
            return root;
        }

        TreeNode* l = searchBST(root->left , val);
        TreeNode* r = searchBST(root->right , val);

        return (l == NULL) ? r : l;
    }
};