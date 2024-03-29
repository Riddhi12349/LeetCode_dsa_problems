class Solution {
public:
    #include<queue>
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
         vector<int> v1;
        while(!q.empty()){
         TreeNode* front = q.front();
      
            while(q.front() != NULL){

                front = q.front();

                if(front->left != NULL)
                q.push(front->left);

                if(front->right != NULL)
                q.push(front->right);

                if(front != NULL)
                v1.push_back(front->val);
                
                q.pop();
            }
            if(q.front() == NULL){
                q.pop();

                if(!q.empty())
                q.push(NULL);
                
                ans.push_back(v1);
                v1.clear();
                
            }
        }
        return ans;
    }
};