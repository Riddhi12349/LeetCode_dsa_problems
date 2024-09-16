class Solution {
    public:
    //LETS CREATE A TRIE
    class TrieNode{
      public:
        TrieNode* children[26];
        TrieNode(){
            for(int i=0; i<26; i++)
                children[i] = NULL;
        }
    };
    
    TrieNode* root;
        
    void insert(string word){
        
        TrieNode* cur = root;
        
        for(char ch : word){
            if(cur->children[ch-'a'] == NULL)
                cur->children[ch-'a'] = new TrieNode();
            cur = cur->children[ch-'a'];
        }
    }   
    
    int find(int idx , string& target , vector<int>& dp){
        
        
        int i=idx , n = target.size() , ans = 1e6;
        
        if(idx==n) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        TrieNode* node = root;
        
        while(i < n){
            
            char ch = target[i];
            
            if(node->children[ch-'a'] == NULL) break;
            
            ans = min(ans , 1 + find(i+1 , target , dp));
            
            node = node->children[ch-'a'];
            i++;
        }
        
        return dp[idx] = ans;
    }
    
    

    int minValidStrings(vector<string>& words, string target) {
        
        root = new TrieNode();
        
        for(auto word : words){
            insert(word);
        }
        
        int n = target.size();
        vector<int> dp(n+1 , -1);
        
        int cnt = find(0 , target , dp);
        
        if(cnt>=1e6) return -1;
        
        return cnt;
        
    }
};