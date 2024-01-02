class Solution {
public:
    unordered_map <TreeNode* , TreeNode*> parent;
    unordered_map <TreeNode* , TreeNode*> mp;
    
    void findParent(TreeNode* root , TreeNode* ptr){
         
        if(root == NULL || ptr == NULL) return;
        
        if(root->left){
            parent[root->left] = root;
            ptr->left = new TreeNode(root->left->val);
            mp[root->left] = ptr->left;
        }
        if(root->right){ 
            parent[root->right] = root;
            ptr->right = new TreeNode(root->right->val); 
            mp[root->right] = ptr->right;
        }

            findParent(root->left , ptr->left);
            findParent(root->right , ptr->right);

    }
    
    // void print(){
    //    for(auto x : mp){
    //       cout << x.first->val << " " << x.second->val << endl;
    //     }
    // }
    
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        if(root == NULL) return NULL;
        
        TreeNode* newRoot = new TreeNode(root->val);
        TreeNode* ptr = newRoot;
        mp[root] = newRoot;
        findParent(root , ptr);
        
        // print();
       
        queue<TreeNode*> q;
        q.push(root); 
        
        while(!q.empty()){
            
            int s = q.size(); 
            int sum = 0; 
            vector<TreeNode*> nodes;
            
            for(int i = 1 ; i <= s ; i++){
                
                TreeNode* f = q.front(); 
                q.pop();
                if(f->left)  q.push(f->left);
                if(f->right) q.push(f->right);

                sum += f->val;
                nodes.push_back(f);
            }
       
            for(int i = 0 ; i < nodes.size() ; i++){
                int tmpSum = sum ;

                if(nodes[i] == root){ mp[nodes[i]]->val = 0; continue;}

                tmpSum -= parent[nodes[i]]->left == NULL ? 0 : parent[nodes[i]]->left->val;
             
                tmpSum -= parent[nodes[i]]->right == NULL ? 0 : parent[nodes[i]]->right->val;
                
                mp[nodes[i]]->val = tmpSum;  
            }          
        }
        
        return newRoot;
    }
};