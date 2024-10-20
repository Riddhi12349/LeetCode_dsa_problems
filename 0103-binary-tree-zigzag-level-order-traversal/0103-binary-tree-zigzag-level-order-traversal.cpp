class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);   int f = 0;
        
        while(!q.empty()){
            
            int s = q.size();
            vector<int> v1(s,0);
            
            for(int i = 1 ; i <= s ; i++){
           
                TreeNode* fr = q.front();
                q.pop();
            
                int idx = (f==0) ? i-1 : s-i;
                v1[idx] = fr->val;
                    
                if(fr->left) q.push(fr->left);
                if(fr->right) q.push(fr->right);
            
           }
            f = !f;
            ans.push_back(v1);
            
        }
        
        return ans;
    }
};