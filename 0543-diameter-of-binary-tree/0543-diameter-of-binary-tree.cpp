class Solution {
public:
 // f = ht , s = dia
    pair<int, int> helper(TreeNode* root){

        if(root == NULL){
            pair<int,int> p;
            p.first = 0;
            p.second = 0;
            return p;
        }

     pair<int,int> p1 =  helper(root->left);
     pair<int,int> p2 =  helper(root->right);

    pair<int, int> ans;

     if(p1.first > p2.first){
         ans.first = p1.first + 1;
     }
     else{
         ans.first = p2.first + 1;
     }

     int dia = max(p1.second , p2.second);
     ans.second = max(p1.first + p2.first + 1 , dia);
     
     return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
       pair<int, int> p = helper(root);
       return p.second-1;
    }
};