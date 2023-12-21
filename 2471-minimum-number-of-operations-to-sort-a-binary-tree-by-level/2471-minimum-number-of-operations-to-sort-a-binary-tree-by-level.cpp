class Solution {
  public:
   
    int find(queue<TreeNode*> q){
        
        vector<int> v1;
        while(!q.empty()){
            v1.push_back(q.front()->val);
            q.pop();
        }
        
        vector<int> v2(v1.begin(),v1.end());
        sort(v2.begin() , v2.end());
     
        unordered_map<int,int> mp;
        for(int i = 0 ; i < v2.size() ; i++){
            mp[v2[i]] = i;
        }
        
        int swaps = 0;
        for(int i = 0 ; i < v1.size() ; i++){
            
            while(i != mp[v1[i]]){
                int pos  = mp[v1[i]];
                swap(v1[i] , v1[pos]);
                swaps++;
            }
        }
     
        return swaps;
    }
    
    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root); int tot_ops = 0;
        
       while(!q.empty()){
            
            int s = q.size(); queue<TreeNode*> q2;
          
         for(int i = 1 ; i <= s ; i++){
            TreeNode* f = q.front();  q2.push(f);
            q.pop();
             
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
         }
            
          tot_ops +=  find(q);
     
        }
        
        return tot_ops;
    }
};