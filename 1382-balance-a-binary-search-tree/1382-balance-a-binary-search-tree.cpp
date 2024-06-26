class Solution {
   public :
    
    vector<int> inorder;
    
    void inorderTrav(TreeNode* root){
        
        if(root == NULL) return ;
        
        inorderTrav(root->left);
        inorder.push_back(root->val);
        inorderTrav(root->right);
        
    }
    
    TreeNode* formBalanceBST(TreeNode* root, int l , int r){
        
        if(l > r) return NULL;
        
        int mid = (l + r)/2;
        
        TreeNode* newRoot = new TreeNode(inorder[mid]);
        
        newRoot->left = formBalanceBST(root , l , mid-1);
        newRoot->right = formBalanceBST(root, mid+1 , r);
        
        return newRoot;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
      inorderTrav(root);
        
      TreeNode* root2 =  formBalanceBST(root , 0 , inorder.size()-1);
        
      return root2;
    }
};