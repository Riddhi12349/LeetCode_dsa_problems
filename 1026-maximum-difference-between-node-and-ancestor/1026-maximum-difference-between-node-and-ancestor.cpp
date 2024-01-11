class Solution {
public:
    int mxdiff;
   // using ll=long long;
    
    void find(TreeNode* root , int mn , int mx){
        
        if(!root) return;
    

      mn = min(mn, root->val);
      mx = max(mx , root->val);
        
   find(root->left , mn , mx);
  
  
   find(root->right , mn, mx);
        
     if(mx != INT_MIN && mn !=  INT_MAX){
         
         cout << "root " << root->val << endl;
         cout << mn << " " << mx << endl;
        mxdiff = max(mxdiff,(mx-mn));}
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        mxdiff=0;
        find(root,INT_MAX,INT_MIN);
        return mxdiff;
    }
};