class Solution {
public:
    unordered_map <string,int> mp1 , mp2;
    
    void findWords(string s1){
        
        int n = s1.size();
        
        for(int i = 0 ; i < n ;){
            
            string word = "";
            
            for(int j = i ; j < n ; j++ , i++){
                if(s1[j] == ' ') break;
                word += s1[j];
            }
            
            mp1[word]++;
            i++;
        }
    }
    
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        vector<string> ans;
        
        findWords(s1); findWords(s2);
        
        for(auto x: mp1){
            if(x.second == 1){
                if(mp2.count(x.first) == 0) ans.push_back(x.first);
            }
        }
        
        for(auto x : mp2){
            if(x.second == 1){
                if(mp1.count(x.first)==0) ans.push_back(x.first);
            }
        }
        
        return ans;
    }
};