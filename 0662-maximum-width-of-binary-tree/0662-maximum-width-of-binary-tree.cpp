class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == NULL){ 
            return 0;
        }
        queue<pair<TreeNode*,long>> q;
        q.push({root , 0});
        int width = 1;

     while(!q.empty()){

            auto front = q.front();
            
            int st_indx = q.front().second;
            int end_indx = q.back().second;

            width = max(width , end_indx - st_indx + 1);

            long level_size = q.size();

         for(int i = 1 ; i<= level_size  ; i++){

            auto front = q.front();

            long indx = front.second - st_indx;
            TreeNode* node = front.first;

            q.pop();

            if(node->left != NULL){
                q.push({node->left , (long)2*indx + 1});
            }
            if(node->right != NULL){
                q.push({node->right , (long)2*indx + 2});
            }
        }
    }

    return width;
 }
};