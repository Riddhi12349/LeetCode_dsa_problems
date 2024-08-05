class Solution {
public:
    string smallestSubsequence(string s) {
        
       vector<int> lastIndx(26 , -1);
       vector<bool> vis(26, false);
        
       for(int i = 0 ; i < s.size() ; i++){
          
           int indx = s[i]-'a';
           
           lastIndx[indx] = i;
           
       }
       
        string res = "";
        
       for(int i = 0 ; i < s.size() ; i++){
           
           char ch = s[i];
           
           int indx = ch-'a';
           
           if(vis[indx] == true) continue;
           
           while(res.size() > 0 && res.back() > ch && lastIndx[res.back()-'a'] > i){
          
               vis[res.back()-'a'] = false;
               res.pop_back();
           }
           
           res += ch;
           vis[indx] = true;
           
       } 
        
        return res;
       
    }
};