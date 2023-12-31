class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        int ans = -1;
        
        for(int i = 0 ; i < s.size() ; i++){
            
            int cnt = 0 , mxlen = -1, f = 0;
            
            for(int j = i+1 ; j < s.size() ; j++){
                
                if(s[j] == s[i]){ 
                    cnt=(j-i-1);
                    mxlen = max(mxlen , cnt);
                 }                
            }
            
           ans = max(ans, mxlen);
        }
        
        return ans;
    }
};