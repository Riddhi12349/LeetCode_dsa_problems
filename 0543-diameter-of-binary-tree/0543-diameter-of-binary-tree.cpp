class Solution {
public:
    int find(TreeNode* root , int& dia){
        
        if(root == NULL) return 0;
        
        int lh = find(root->left , dia);
        int rh = find(root->right , dia);
        
        dia = max(dia , lh + rh + 1);
        return max(lh , rh) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
       
        int dia = 0;
        find(root , dia);
        
        return dia-1;
    }
};