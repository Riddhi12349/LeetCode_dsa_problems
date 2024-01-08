class Solution {
public:
    void findPath(TreeNode* root , int l , int h, int& sum){
        
        if(root == NULL) return;
        
        if(root->val > h)
            findPath(root->left , l , h, sum);
        else if(root->val < l)
            findPath(root->right , l , h, sum);
        else{
            sum += root->val;
            findPath(root->left , l , h , sum);
            findPath(root->right , l, h, sum);
        }
    }
    
   int rangeSumBST(TreeNode* root, int low, int high) {
      
       int sum = 0 ,f=0;
     
       findPath(root ,low , high , sum);
      
       return sum;
    }
};