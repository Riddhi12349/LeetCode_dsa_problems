class Solution {
public:
    TreeNode* f(vector<int> v1 , int l , int h){
   
      if(l > h){ return NULL; }
       int  m = (l + h)/2;
        TreeNode* root = new TreeNode(v1[m]);
       
        root->left = f(v1 , l , m-1);
        root->right = f(v1 , m+1 , h);
        
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v1;
        
        ListNode* p = head;
        while(p != NULL){
            v1.push_back(p->val);
            p = p->next;
        }

        return f(v1 , 0 , v1.size()-1);
    }
};