class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        if(root==NULL) return {};
        
        vector<int> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int s = q.size() , mx = INT_MIN;
             
            for(int i = 1 ; i <= s ; i++){
                
                TreeNode* fr = q.front();
                q.pop();
                
                mx = max(mx , fr->val);
                
                if(fr->left) q.push(fr->left);
                if(fr->right) q.push(fr->right);
            }
            
            ans.push_back(mx);
        }
        
        return ans;
    }
};