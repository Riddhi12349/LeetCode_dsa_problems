// class Solution {
// public:
// int cnt;
//    int dfs(TreeNode* root , int cnt){
//        if(root->left != NULL){
//            dfs(root->left , cnt + 1);
//        }
//        if(root->right != NULL){
//            dfs(root->right , cnt + 1);
//        }
       
//            return cnt;
       
//    }
//     int max_path = INT_MIN;
//     int longestZigZag(TreeNode* root) {
        
//         if(root == NULL){
//             return INT_MIN;
//         }
       
//         int cnt = dfs(root , 0);
//         if(max_path < cnt){ max_path = cnt; }
//         int p = longestZigZag(root->left);
//         int q = longestZigZag(root->right);
//         max_path = max(max_path , max(p , q));
//         return max_path;
//     }
// };

class Solution {
public:
  int ans = 0;
pair<int,int> dfs(TreeNode* root){

    if(root == NULL){ return {-1,-1};}

    pair<int,int> left = dfs(root->left);
    pair<int,int> right = dfs(root->right);
 
  ans = max(ans , max(left.second , right.first)+1);
  return {left.second + 1 , right.first + 1};

}

int longestZigZag(TreeNode* root){
    dfs(root);
    return ans;
}
};
