class Solution {
public:
    bool find(TreeNode* p1 , TreeNode* p2){
        
        if(p1 == NULL && p2 == NULL)
            return true;
        
        if(p1 == NULL || p2 == NULL)
            return false;
        
        if(p1->val != p2->val)
            return false;
        
        bool a1 = find(p1->left , p2->right);
        bool a2 = find(p1->right, p2->left);
        
        return a1 & a2;
    }
    
    bool isSymmetric(TreeNode* root) {
     
        return find(root , root);
    }
};