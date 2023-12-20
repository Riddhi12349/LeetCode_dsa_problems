class Trie {
public:
    struct TrieNode {
        bool isEndOfWord;
        TrieNode* children[26];
    };
       
    TrieNode* getNode() {
        
        TrieNode* newNode = new TrieNode();       
        newNode->isEndOfWord = false;
        
        for(int i = 0 ; i < 26 ; i++){
            newNode->children[i] = NULL;
        }
        
        return newNode;
    }
    
    TrieNode* root;
    
    Trie(){
       root  = getNode();
    }
  
    //  apple  r->a->p->p->l->e
    
    void insert(string word) {
        
        TrieNode* ptr = root;
        
        for(int i = 0 ; i < word.size() ; i++){
     
            int indx = (word[i] - 'a');
            if(ptr->children[indx] == NULL) { 
                ptr->children[indx] = getNode();
            }
                ptr = ptr->children[indx];
        }
        
          ptr->isEndOfWord = true;
    }
    
    bool search(string word) {
        
        TrieNode* ptr = root;
        
        for(int i = 0 ; i < word.size() ; i++){
            int indx = word[i]-'a';
            if(ptr->children[indx] == NULL){ 
                return false;
            }
            ptr = ptr->children[indx];
        }
       if(ptr  && ptr->isEndOfWord )
          return true;
        
        return false;
    }
    
    bool startsWith(string prefix) {
       
        TrieNode* ptr = root;
        
        for(int i = 0 ; i < prefix.size() ; i++){
            int indx = prefix[i]-'a';
            if(ptr->children[indx] == NULL){ return false; }
                ptr = ptr->children[indx];
        }
              
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */