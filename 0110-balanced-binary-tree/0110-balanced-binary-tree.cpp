class Solution {
public:
    // f -> ht, s -> T/F
    pair<int,bool> helper(TreeNode* root){
    
    pair<int,bool> ans;
       
        if(root == NULL){
            ans.first = 0;
            ans.second = true;
            return ans;
        }

    pair<int,bool> lp = helper(root->left);
    pair<int,bool> rp = helper(root->right);

       if(lp.first > rp.first){
           ans.first = lp.first + 1;
       }
       else{
           ans.first = rp.first + 1;
       }

       bool temp = lp.second && rp.second;
       int diff = (lp.first - rp.first);

       if(diff == 0|| diff == 1 || diff == -1){
           ans.second = true && temp;
       }
       else{
           ans.second = false;
       }

       return ans;
    }
    bool isBalanced(TreeNode* root) {
    
        if(root == NULL){
            return true;
        }
    pair<int , bool> p =  helper(root);
    return p.second;
    }
};