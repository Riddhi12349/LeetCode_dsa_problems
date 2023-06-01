class Solution {
public:

    int maxPathSumHelper(TreeNode* root , int& ans){

        if(root == NULL){
            return 0;
        }

     int left = maxPathSumHelper(root->left , ans);
     int right = maxPathSumHelper(root->right , ans);

      
        int p = max(root->val , root->val +  max(left , right)); //35, 25
        ans = max(ans , max(p,root->val+left+right)); //42 ,34
        return p;
    }
    int maxPathSum(TreeNode* root) {
        
       if(root == NULL){
            return 0;
        }

       int ans = INT_MIN;
       int p = maxPathSumHelper(root , ans);
       return max(p , ans);
    }
};