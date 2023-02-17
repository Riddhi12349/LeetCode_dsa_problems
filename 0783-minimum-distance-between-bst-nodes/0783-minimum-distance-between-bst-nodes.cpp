class Solution {
public:  

vector<int> v1;

  void inorder(TreeNode* root){

        if(root == nullptr) { return ; }
        
        inorder(root->left );
       v1.push_back(root->val);
       inorder(root->right);
   }
   
    int minDiffInBST(TreeNode* root) {

        inorder(root);
        int diff = INT_MAX;
        for(int i = 0 ; i < v1.size()-1 ; i++){
            int x = v1[i+1]-v1[i];
              diff = min(x , diff);
        }
        return diff;
    }
       
   
};