class Solution {
public:
    string decodeAtIndex(string s, int k) {
        
        long long len = 0; int n = s.size();
        
        // finding length of decoded string
        for(int i = 0 ; i < n ; i++){
            if(isalpha(s[i])){
                len++;
            }
            else{
                len = len*(s[i]-'0');
            }
        }
        
        for(int i = n-1 ; i >= 0 ; i--){
            k = k % len;
            if(k == 0 && isalpha(s[i])){
                string t = "";
                t += s[i];
                return t;
            }
           else if(!isalpha(s[i])){
                int d = (s[i] - '0');
                len = len/d;
            }
            else{
                len = len-1;
            }
        }
                   
                  return "";
        
    }
};