class Solution {
public:
    string makeFancyString(string s) {
        
        int n = s.size();
        
        for(int i = 0 ; i < n ; i++){
            
            if(i+2 < n && s[i] == s[i+1] && s[i+1] == s[i+2]){
                s[i] = '#';
            }
        }
        
        string ans = "";
        
        for(auto ch : s){
            if(ch != '#'){
                ans += ch;
            }
        }
         
        
        return ans;
    }
};