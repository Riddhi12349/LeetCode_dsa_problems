class Solution {
public:
    int minSwaps(vector<int>& v1){
        
        //a = [7,6,8,5] => [{5,0},{6,1},{7,2},{8,3}]
         
        int n = v1.size(), swaps=0;
        
        vector<int> v2(v1.begin() , v1.end());
        
        sort(v2.begin() , v2.end());
        
        unordered_map<int,int> mp;
        for(int i=0; i<n;  i++){
            mp[v2[i]]=i;
        }
        
        for(int i=0; i<n; i++){
            
            while(i != mp[v1[i]]){
                swap(v1[i] , v1[mp[v1[i]]]);
                swaps++;
            }
        }
        
        return swaps;
    }
    
    int minimumOperations(TreeNode* root) {
        
        int totSwaps = 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
              vector<int> v1;
              int s = q.size();
            
              for(int i = 1 ; i <= s ; i++){
                  
                  TreeNode* fr = q.front();
                  q.pop();
                  
                  if(fr->left) q.push(fr->left);
                  if(fr->right) q.push(fr->right);
                  
                  v1.push_back(fr->val);
              }
            
              totSwaps += minSwaps(v1);            
        }
        
        return totSwaps;
    }
};