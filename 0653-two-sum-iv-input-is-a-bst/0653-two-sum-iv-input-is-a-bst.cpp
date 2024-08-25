class Solution {
public:
    class BstIterator{
        
      public: 
        
        stack<TreeNode*> st;
        bool reverse;
        
        BstIterator(TreeNode* root , bool rev){
          
            reverse = rev;
            pushAll(root);
                  
        }
        
        int next(){
            
            TreeNode* topNode = st.top();
            st.pop();
            
            int ans = topNode->val;
            
            if(reverse == false){
                //After taking out next you have to insert right , b/c prev only left was inserted
                //ACT LIKE BEFORE => mtlb piche se
                pushAll(topNode->right);
            }
            else{
                //ACT LIKE NEXT => mtlb aage se
                 pushAll(topNode->left);
            }
            
            return ans;
        }
        
        void pushAll(TreeNode* root){
        
             if(root == NULL) return;
            
             if(reverse == true){
                 //push piche se
                 
                 st.push(root);
                 
                 while(root->right != NULL){
                     st.push(root->right);
                     root = root->right;
                 }
             }
             else{
                //push aage se
                
                st.push(root);
                
                while(root->left != NULL){
                    st.push(root->left);
                    root = root->left;
                }
                
            }
            
        }
        
    };
    bool findTarget(TreeNode* root, int k) {
        
     //  **** SC = From O(N) Can be Optimised to O(H) using Bst-ITERATOR ****
           
        BstIterator st_obj(root , false);
        BstIterator end_obj(root, true);
        
        int st_val = st_obj.next()  , end_val = end_obj.next();
        
        while(st_val < end_val){
           
            cout << st_val << " " << end_val << endl;
            
            if(st_val + end_val == k){
                return true;
            }
            else if(st_val + end_val > k){
                end_val = end_obj.next(); 
            }
            else{
                st_val = st_obj.next();
            }
        }
        
        return false;
    }
};