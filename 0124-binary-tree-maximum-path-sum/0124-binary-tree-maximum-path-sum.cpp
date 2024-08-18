class Solution {
public:
    pair<int,int> find(TreeNode* root ){
        
        if(root == NULL){ 
            return {0,-1e4}; 
        }
        
        auto p1 = find(root->left);
        auto p2 = find(root->right);
     
        int ls = root->val + p1.first;
        int rs = root->val + p2.first;
        int root_s = ls + rs - root->val;
        
        pair<int,int> ans;
        
        ans.first = max({root->val , ls, rs});
        ans.second = max({root_s , ans.first});
        ans.second = max(ans.second , max(p1.second , p2.second));
     
        return ans;
    }
    
    int maxPathSum(TreeNode* root) {
        
        auto p1 = find(root); //{sum_at_root_level , mxsum_obtained}
        return p1.second;
        
    }
};