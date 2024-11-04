class Solution {
public:
    string compressedString(string word) {
        
        int n = word.size(); string ans = "";
        

        for(int i = 0 ; i < n ; i++){
            
            int cnt = 1; char ch = word[i];
                
            while(i+1 < n && word[i] == word[i+1] && cnt < 9){
                i++;
                cnt++;
            }
            
            ans += to_string(cnt);
            ans += ch;
        }
    
          return ans;
    }
};