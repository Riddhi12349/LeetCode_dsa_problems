class Solution {
public:
    unordered_map <int,vector<int>> mp2;
    
    void formTree(TreeNode* root){
        
        if(root == NULL) return;
        
        int rt = root->val;
        
        int l = mp2[rt][0] , r = mp2[rt][1];
        
     if(l != -1)   root->left = new TreeNode(l);
        
        formTree(root->left);
        
     if(r != -1)   root->right = new TreeNode(r);
        
        formTree(root->right);
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& a) {
        
        unordered_map <int,int> mp ; // node => parent
        
        for(int i = 0 ; i < a.size() ; i++){
            mp[a[i][1]] = -1;
            mp[a[i][0]] = -1;
        }
       
        for(int i = 0 ; i < a.size() ; i++){
            mp[a[i][1]] = a[i][0];
        }
        
      /*  
        for(auto x : mp){
            cout << "node = " << x.first << " parent" << x.second << endl;           
        }
      */  
        int rt = -1;
        for(auto x : mp){
            if(x.second == -1) rt = x.first;
        }
       
          
        for(int i = 0 ; i < a.size() ; i++){
                mp2[a[i][0]] = {-1,-1};
                mp2[a[i][1]] = {-1,-1};
        }
        
        for(int i = 0 ; i < a.size() ; i++){
            
            int node = a[i][1] , par = a[i][0];
           
            int l = mp2[par][0] , r = mp2[par][1];
            
            if(a[i][2]==1) { l = node; }
            else{ r = node; }
            
     //       cout << "parent = " << par << "left = " << l << "rt = " << r << endl;
            
            mp2[par] = { l , r };
        }
       /* 
        for(auto x : mp2){
            int node = x.first;
            vector<int> v1 = x.second;
            int l = v1[0] , r = v1[1];
            cout << node << " " << l << " " << r << endl;
        }
     */   
        TreeNode* root = new TreeNode(rt);
        
        formTree(root);
             
        return root;
    }
};