class Solution {
public:
    string compressedString(string s) {
      
        int n = s.size(); 
        
        string ans = "";
        
        for(int i = 0 ; i < n ; ){
            
            char ch = s[i];
            int cnt = 1 , j = i+1;
            
            for( ; j < n ; j++ ){
                if(s[j] == ch && cnt < 9) cnt++;
                else break; 
            }
            
            i = j;
            ans += to_string(cnt);
            ans += ch;
            
        }
        
        return ans;
        
    }
};