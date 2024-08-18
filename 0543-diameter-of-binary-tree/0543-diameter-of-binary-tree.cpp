class Solution {
public:
    pair<int,int> find(TreeNode* root){
    
        if(root == NULL){
            return {0 , 0};
        }
        
        auto p1 = find(root->left);
        auto p2 = find(root->right);
        
        pair<int,int> ans;
        
        ans.first = max(p1.first , p2.first) + 1;
        
        int dia_child = max(p1.second , p2.second);
        int dia_root = p1.first + p2.first + 1;
        
        ans.second = max(dia_root , dia_child);
        
        return ans;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        pair<int,int> p1 = find(root); //{ht , diameter} 
        return p1.second-1;
        
    }
};