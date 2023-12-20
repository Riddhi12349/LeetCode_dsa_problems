class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);  int lev = 0; 
        
        stack<int> st; 
        
        while(!q.empty()){
         
            int s = q.size();
            lev++;
            
            queue<TreeNode*> q2;
            
            for(int i = 1 ; i <= s ; i++){
                
                TreeNode* f = q.front();
                q.pop();
                
               if(f->left)  q.push(f->left);
               if(f->right) q.push(f->right);
            
                if(lev % 2 != 0 && f != NULL){
                    q2.push(f);
                    if(f->left) st.push(f->left->val);
                    if(f->right) st.push(f->right->val);
                }
            }
        
             
                while(!st.empty() && (lev % 2 != 0) && !q2.empty()){
                    TreeNode* f = q2.front(); q2.pop();
                    f->left->val = st.top(); st.pop();
                    f->right->val = st.top(); st.pop();
                }
        }     
           
        return root;
    }
};