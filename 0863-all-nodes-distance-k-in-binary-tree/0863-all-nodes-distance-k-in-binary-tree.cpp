class Solution {
public:
    unordered_map < TreeNode* , TreeNode* > parent;
    
    void findPar( TreeNode* root , TreeNode* par){
        
        if(root == NULL){
            return;
        }
        
        parent[root] = par;
        
        findPar(root->left , root);
        findPar(root->right , root);
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      
         findPar(root , NULL);
         
         unordered_map <TreeNode*,int> mp_vis;
         queue<TreeNode*> q;
        
         mp_vis[target]++;
         q.push(target);
        
         int level = 0; vector<int> ans;
        
         while(!q.empty()){
             
          int s = q.size();
          level++;
             
          for(int i=1 ; i <= s ; i++){
              
             TreeNode* f = q.front();
             q.pop();
             
             if(level == k+1){
                ans.push_back(f->val); 
             }
              
             if(f->left && mp_vis.count(f->left) == 0){
                 q.push(f->left);
                 mp_vis[f->left]++;
             }
             
             if(f->right && mp_vis.count(f->right) == 0){
                 q.push(f->right);
                 mp_vis[f->right];
            }
              
             if(parent[f] && mp_vis.count(parent[f]) == 0){
                 q.push(parent[f]);
                 mp_vis[parent[f]]++;
             }
              
        } 
             
    }
        
         return ans;
    }
};