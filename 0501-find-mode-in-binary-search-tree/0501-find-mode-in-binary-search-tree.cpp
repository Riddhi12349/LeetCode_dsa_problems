/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root , vector<int>& a){
        
        if(root == NULL) return;
        
        inorder(root->left , a);
        if(root!=NULL) a.push_back(root->val);
        inorder(root->right , a);
    }
    
    vector<int> findMode(TreeNode* root) {
 
        vector<int> a ;
        inorder(root , a);
      
        priority_queue<pair<int,int> > pq;
        unordered_map<int,int> mp;
        for(auto e : a){
            mp[e]++;
        }
        for(auto x : mp){
            pq.push({x.second , x.first});
        }
        int f = pq.top().first;
        int m = pq.top().second;
        vector<int> ans;
        
        while(!pq.empty()){
            if(pq.top().first == f){
                ans.push_back(pq.top().second);
                pq.pop();
            }
            else break;
        }
        
        return ans;
    }
};