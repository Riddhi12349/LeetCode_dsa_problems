


class Solution {
    vector<int>dp;int n;
    struct TrieNode{
        // unordered_map<char,TrieNode*>children;
        TrieNode*children[26];
        TrieNode(){
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }
    };

   // class Trie{
        TrieNode * root;

   /* public: 
        Trie(){
            root = new TrieNode();
        }
*/
        void insert(string &word){
            TrieNode*node=root;
            for(int i=0;i<word.size();i++){
                char child = word[i];
                if(node->children[child-'a']==NULL)
                    node->children[child-'a']=new TrieNode();
                node=node->children[child-'a'];
            }
        }

        int helper(int idx,string &target,vector<int>&dp){
            if(idx==target.size())return 0;
            TrieNode*node=root;
            if(dp[idx]!=-1)return dp[idx];
            int ans=1e6;
            int i=idx;
            int n=target.size();
            while(i<n){
                 char child = target[i];
                 if(node->children[child-'a']==NULL)break;
                 ans=min(ans,helper(i+1,target,dp)+1);
                 node=node->children[child-'a'];
                 i++;
            }
            return dp[idx]=ans;
        }
  //  };
public:
    int minValidStrings(vector<string>& words, string target) {
        n=target.size();
        
        root = new TrieNode();
        
       // Trie t ;
        for(auto it:words) insert(it);
        dp=vector<int>(n,-1);
        int ans= helper(0,target,dp);
        if(ans>=1e6)return -1;
        return ans;
    }
};