class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         
        //{ vertical , { level(top-to-bottom-incr-order) , list_of_nodes_at_that_Level } }
        map<int , map <int , multiset<int > > > mp_x;
        
        //multiset => so that same level nodes in sorted order and duplicate value nodes are NOT discarded
        
        queue <pair<TreeNode* , vector<int> > > q; //{NODE , {ROW , COLM} }
        
        q.push({root , {0,0}});
        
        while(!q.empty()){
           
            auto p1 = q.front();
            q.pop();
            
            TreeNode* node = p1.first;
            int r = p1.second[0]  , c = p1.second[1];
           
            if(node->left)
                q.push({node->left , {r+1 , c-1}});
            
            if(node->right)
                q.push({node->right , {r+1 , c+1}});
            
            
            mp_x[c][r].insert(node->val);
            
        }
        
        vector<vector<int>> ans;
        
        for(auto p : mp_x){
            
            int col = p.first;
            
            vector<int> nodes_levelWise;
            
            for(auto q : p.second){
                
                nodes_levelWise.insert(nodes_levelWise.end() ,
                                       q.second.begin() , q.second.end());
                
            }
            
            ans.push_back(nodes_levelWise);
            
        }
        
        return ans;
        
    }
};