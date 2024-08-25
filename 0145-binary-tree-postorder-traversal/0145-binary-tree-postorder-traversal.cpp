class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        stack <pair<TreeNode*,bool>> st;
        
        st.push({root , false });
        
        while(!st.empty()){
            
            auto p = st.top();
            st.pop();
            
            if(p.first == NULL){
                continue;
            }
            
            TreeNode* cur = p.first;
            
            if(p.second == false){
                
                st.push({cur , true});
                st.push({cur->right , false});
                st.push({cur->left , false});
            }
            else{
                //IF ALREADY VISITED
                ans.push_back(cur->val);
            }
        }
        
        return ans;
    }
};