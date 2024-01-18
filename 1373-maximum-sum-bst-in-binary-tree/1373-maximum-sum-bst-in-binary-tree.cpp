class Solution {
public:
    
    int mxsum=0;
    
    class Node{
      public:
        bool isbst;
        int mx;
        int mn;
        int sum;
  
        Node(){
            isbst = true;
            mx = INT_MIN;
            mn = INT_MAX;
            sum = 0;
        }
    };
    
    Node find(TreeNode* root){
        
        if(root==NULL) 
            return Node();
        
       Node n;
       Node l = find(root->left);
       Node r = find(root->right);
        
        if(l.isbst && r.isbst && root->val > l.mx 
           && root->val < r.mn){
            
            mxsum = max(mxsum , root->val + l.sum + r.sum);
            
            n.isbst = true;
            n.mx = max(root->val , r.mx);
            n.mn = min(root->val , l.mn);
            n.sum = root->val + l.sum + r.sum;
            
            return n;
        }
        
        n.isbst = false; 
        n.sum =  max({root->val,l.sum , r.sum});
        
        return n;
    }
    
    int maxSumBST(TreeNode* root) {
       mxsum=0;
       find(root);
       return mxsum;
    }
};