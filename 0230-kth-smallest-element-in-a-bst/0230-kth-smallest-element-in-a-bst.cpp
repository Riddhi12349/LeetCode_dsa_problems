class Solution {
public:
   
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL){
            return 0;
        }
        stack<TreeNode*> st;
        vector<int> v1;
        // inorder traversal------->
        TreeNode* p = root;
        while(p != NULL){
            st.push(p);
            p = p->left;
        }
        while(!st.empty()){
            p = st.top();
            v1.push_back(p->val);
            st.pop();
            if(p->right != NULL){
                p = p->right;
                while(p != NULL){
                    st.push(p);
                    p = p->left;
                }
            }
        }
        return v1[k-1];
    }
};