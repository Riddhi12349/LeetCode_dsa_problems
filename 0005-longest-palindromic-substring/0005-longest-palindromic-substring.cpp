class Solution {
public:
    string longestPalindrome(string s) {
      
      int n = s.size(); int mxlen = 1;

      string ans = "";
      ans += s[0];
      //check if there is odd length palindrome
    
      for(int i = 1 ; i < n-1; i++){
          int p = i-1 , q  = i+1;
          int cnt = 1;
          while(p >= 0 && q < n && s[p] == s[q]){
              p--; q++; cnt += 2;
          }
          if(mxlen < cnt){
              mxlen = cnt;
              ans= "";
              for(int k = p+1 ; k < q ; k++){
                  ans.push_back(s[k]);
              }
          }
      } 
    
        // check if even length palindrome
    
        for(int i = 0 ; i <n-1 ; i++){
            int p = i , q = i+1;
            int cnt = 0;
            while(p >= 0 && q < n && s[p] == s[q]){
                p--; q++; cnt += 2;
            }
            if(mxlen < cnt){
                mxlen = cnt;
                ans = "";
                for(int k = p+1 ; k < q ; k++){
                 ans.push_back(s[k]);
                }
            }
        }
    
        return ans;
    }
};

