class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string ans = "";
        int p = word1.size() , q = word2.size(); 
        int s = min(p,q);
        int i = 0;
        for( ; i < s ; i++){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        
        if(p > q){
            p = p-q;
            while(p>0){
                ans.push_back(word1[i]);
                i++; 
                p--;
            }
        }
        else{
            q = q-p;
            while(q>0){
                ans.push_back(word2[i]);
                i++; 
                q--;
            }  
        }
        
        return ans;
    }
};