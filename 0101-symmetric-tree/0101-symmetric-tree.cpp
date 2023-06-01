class Solution {
public:

    bool helper(TreeNode* p , TreeNode* q){

      if(p == NULL && q == NULL) return true;

      if(p == NULL || q == NULL) return false;

      if(p->val == q->val){
        
          bool a1 = helper(p->left , q->right);
          bool a2 = helper(p->right , q->left);
         return a1 && a2;
      }
      else{
          return false;
      }
    }
    bool isSymmetric(TreeNode* root) {
       return helper(root->left , root->right);  
    }
};