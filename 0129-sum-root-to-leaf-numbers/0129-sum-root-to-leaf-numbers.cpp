/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

        int sum = 0;
    void sumNumbersHelper(TreeNode* root , int n){

        if(root == NULL){
            return ;
        }
            n = n * 10 + root->val;
        sumNumbersHelper(root->left , n);
        sumNumbersHelper(root->right , n);
        if(root->left == NULL && root->right == NULL)
        sum += n;
      //  n = n/10;
   
    }

    int sumNumbers(TreeNode* root) {
        
     sumNumbersHelper(root , 0);
     return sum;
    }
};