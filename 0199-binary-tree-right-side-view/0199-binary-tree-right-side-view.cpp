class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
      
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        queue <TreeNode*> q; // { NODE , LEVEL }
        
        q.push(root);
       
        while(!q.empty()){
            
            int s = q.size();
            int last = -1e4;
            
            for(int i=1 ; i<=s ; i++){
                
                TreeNode* f = q.front();
                q.pop();
                
                if(f->left)
                    q.push(f->left);
             
                if(f->right)
                    q.push(f->right);
                
                last = f->val;
            }
            
            if(last != -1e4)
                ans.push_back(last);
            
        }
        
        return ans;
        
    }
};