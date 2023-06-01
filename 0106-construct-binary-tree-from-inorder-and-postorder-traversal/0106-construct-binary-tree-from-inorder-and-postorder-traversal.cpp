class Solution {
public:

 TreeNode* helper(vector<int>& inorder , 
    vector<int>& postorder , int in_i , int in_j , int post_i , int post_j ){

        if(in_i > in_j || post_i > post_j){
            return NULL;
        }

        int k;
        for(k = in_i ; k <= in_j ; k++){
            if(postorder[post_j] == inorder[k]) break;
        }

        TreeNode* root = new TreeNode(postorder[post_j]);
         int len = k - in_i;

        root->left = helper(inorder ,
        postorder , in_i , k-1 , post_i , post_i + len-1);

        root->right = helper(inorder ,
         postorder , k+1 , in_j , post_i+len , post_j-1);
        
        return root;
    }
  
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         return helper(inorder , 
         postorder , 0 , inorder.size()-1 , 0 , postorder.size()-1); 
    }
};