class Solution {
public:
    void findLeafNodes(TreeNode* root , vector<int> &v){
        
        if(!root) return ;
        
        if(!root->left && !root->right) 
            v.push_back(root->val);
        
        findLeafNodes(root->left , v);
        findLeafNodes(root->right , v);
        
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> v1,v2;
        findLeafNodes(root1 , v1);
        findLeafNodes(root2 , v2);
        
        if(v1.size() != v2.size()) return false;
        
        for(int i = 0 ; i < v1.size() ; i++){
            if(v1[i]!= v2[i]) return false;
        }
        
        return true;
    }
};