/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
//stack = [1,5,10,9,13]
//[2,6,14,11,7,3,12,8,4,]
class Solution {
public:
  
    void traverse(Node* root , vector<int>& ans){
        
        if(root == NULL) return;
        
        for(auto x : root->children){
            traverse(x , ans);
        }
        
        if(root){
            ans.push_back(root->val);
        }
    }
    vector<int> postorder(Node* root) {
     /*   
        vector<int> ans;
        traverse(root , ans);
        return ans;
      */
      
      if(root == NULL) return {};
        
      vector<int> ans;
      
  
      stack<pair<Node*,int>> st;
      st.push({root , 0}); //[NODE,VIS]
      
      while(!st.empty()){
            
            auto p = st.top();
            st.pop();
            
            if(p.second == 0){
               
               st.push({p.first , 1});       
               
               Node* topNode = p.first;
               int size = topNode->children.size();
               
               for(int idx = size-1 ; idx >= 0 ; idx--){
                  st.push({topNode->children[idx] , 0});
               }
            }
            else{
                 ans.push_back(p.first->val); 
            }
      }
      
      return ans;
        
    }
};