class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* p = root;

        while(!st.empty() || p!= NULL){

            if(p != NULL){
                st.push(p);
                p = p->left;
            }
            else{
                TreeNode* top = st.top();
                st.pop();
                ans.push_back(top->val);
                 p = top->right;
            }
        }
        
        return ans;
    }
};