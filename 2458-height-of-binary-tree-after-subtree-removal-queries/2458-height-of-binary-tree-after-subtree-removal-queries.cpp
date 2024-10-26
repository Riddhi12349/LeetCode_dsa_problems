class Solution {
public:
    int n;
    vector<int> NodeLevel , NodeHt ;
    vector<pair<int,int>> top2_ht;
    
    int findHeight(TreeNode* root , int level){
        
        if(root == NULL) return 0;
        
        // will find recursively ht of left and rt subtrees
        
        int ht = 1 + max(findHeight(root->left, level+1) , 
                         findHeight(root->right , level+1));
        
        NodeLevel[root->val] = level;
        NodeHt[root->val] =  ht;
        
        if(ht > top2_ht[level].first){
            top2_ht[level].second = top2_ht[level].first;
            top2_ht[level].first = ht;
        }
        else if(ht > top2_ht[level].second){
            top2_ht[level].second = ht;
        }
        
        return ht;
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        
        n = 1e5+1;
        NodeLevel.resize(n , 0); // will find level of each node
        NodeHt.resize(n , 0);    // ht of each node from root node
        top2_ht.resize(n , {0,0}); //  top2 ht(s) considering that node
        
        findHeight(root , 0);  // will find ht of each node starting from root node

        vector<int> ans;
        
        for(int NodeToBeRemoved : queries){
            
            int level = NodeLevel[NodeToBeRemoved];
            int ht = NodeHt[NodeToBeRemoved];
            
            int mxHt = (top2_ht[level].first == ht) ? top2_ht[level].second : top2_ht[level].first;
            
            ans.push_back(mxHt + level - 1);
        }
        
        return ans;
    }
};