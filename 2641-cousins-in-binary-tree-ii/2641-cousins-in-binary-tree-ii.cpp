class Solution {
public:
    unordered_map <TreeNode*,TreeNode*> parent , mp;

    void findParent(TreeNode* root , TreeNode* ptr){
        if(root == NULL) return ;
        mp[root]=ptr;

        if(root->left) {
            parent[root->left] = root;
            ptr->left = new TreeNode(root->left->val);
            }
        if(root->right){ 
            parent[root->right] = root;
            ptr->right = new TreeNode(root->right->val);
            }
            
        findParent(root->left , ptr->left);
        findParent(root->right , ptr->right);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        TreeNode* newRoot = new TreeNode(0);
        TreeNode* ptr = newRoot;
       
        findParent(root , ptr);
     
        //bfs
        queue<TreeNode*> q;
        q.push(root); 
  
        while(!q.empty()){
            
            int s = q.size();
            queue<TreeNode*> q2; int sum=0;

            for(int i = 1 ; i <= s ; i++){
               TreeNode* f = q.front();
               q.pop();
               sum += f->val;
               q2.push(f);
                
               if(f->left)  q.push(f->left);
               if(f->right) q.push(f->right);
            }

            while(!q2.empty()){
                //cout <<"hello!" <<endl;
               TreeNode* f = q2.front(); q2.pop();
               if(f == root) continue;

          int s1 = parent[f]->left ? parent[f]->left->val :0;
          int s2 = parent[f]->right  ? parent[f]->right->val :0;
          mp[f]->val = (sum - s1 - s2); 
          // cout << f->val << " " << mp[f]->val << endl;
                 }
        }
        return newRoot;
    }
};