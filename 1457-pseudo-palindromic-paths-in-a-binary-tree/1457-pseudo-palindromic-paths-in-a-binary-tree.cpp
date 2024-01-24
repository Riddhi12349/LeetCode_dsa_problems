class Solution {
public:
    int v1[10];
    
    bool ispossible(){
     int f=0;
        for(auto x : v1){
            if(x % 2 != 0){
                if(f != 0) return false;
                f=1;
            }   
        }
       
       return true;     
    }
    
  /*  void print(vector<int>& v1){
        for(auto x :v1)
            cout << x << " ";
        cout << endl;
    }*/
    
    int find(TreeNode* root){
     
        if(root == NULL)
            return 0;
        
        v1[root->val]++;
      int a = find(root->left);
      int b = find(root->right);
        
      int t = a+b;
      
      if(!root->left && !root->right && ispossible())
          t+=1;
      
      // print(v1);
        
       v1[root->val]--;
       return t;        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
      
        return find(root);
    }
};