class Solution {
public:
    using ll = long long;
    
    int widthOfBinaryTree(TreeNode* root) {
        
        int mxWidth = 0;
        
        queue< pair<TreeNode* , ll> > q; //{NODE , INDEX}
      
        q.push({root , 0});
        
        while(!q.empty()){
            
           int s = q.size();
           ll fi = -1, li =  -1;
            
           for(int i=1 ; i <= s ; i++){
            
            auto p = q.front();
            q.pop();
                           
            TreeNode* node = p.first;
            int indx = p.second;
            
            if(fi == -1) fi = indx;
            li = indx;
               
            if(node->left) q.push({ node->left , (ll)2*indx });
            if(node->right) q.push({node->right , (ll)2*indx + 1});
           
           }
            
            int width = li-fi+1;
            mxWidth  = max(mxWidth , width);
        }
        return mxWidth;
    }
};