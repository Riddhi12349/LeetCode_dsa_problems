class Solution {
public:
    int find(TreeNode* root , int& mxSum){
        
        if(root == NULL) return 0;
        
        int ls = find(root->left , mxSum);
        int rs = find(root->right , mxSum); 
         
 
        int sum = max(root->val , root->val + max(ls, rs));
        
        mxSum = max({mxSum , sum , root->val + ls + rs});
        
        return sum;
    }
    
    int maxPathSum(TreeNode* root) {
        
        int mxSum = INT_MIN;
        find(root , mxSum);
        
        return mxSum;
    }
};