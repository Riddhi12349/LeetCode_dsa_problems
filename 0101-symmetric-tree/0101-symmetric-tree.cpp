class Solution {
public:

    bool isSymmetricHelper(TreeNode* root1 , TreeNode* root2){

        if(root1 == NULL && root2 == NULL){
            return true;
        }

        if(root1 == NULL || root2 == NULL){
            return false;
        }
        if(root1->val != root2->val){
            return false;
        }

        bool ans1 = isSymmetricHelper(root1->left , root2->right);
        bool ans2 = isSymmetricHelper(root1->right , root2->left);

        return ans1 && ans2;
    }
    bool isSymmetric(TreeNode* root) {
     return   isSymmetricHelper(root , root);
    }
};