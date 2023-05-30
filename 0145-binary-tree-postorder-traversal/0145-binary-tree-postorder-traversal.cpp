class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
       
        stack<TreeNode*> s1 , s2;
        vector<int> ans;

        if(root == NULL){ return ans;}
        
        s1.push(root);
        while(!s1.empty()){
            TreeNode* top = s1.top();
            s1.pop();
            s2.push(top);
            if(top->left != NULL){ s1.push(top->left); }
            if(top->right != NULL){ s1.push(top->right); }
        }

        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }

        return ans;
    }
};