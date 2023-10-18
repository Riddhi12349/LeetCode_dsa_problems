class Solution {
public:
    // ** since palindrome is the string whose reverse and without reverse is same.
    // ** since we have to find the longest common palindromic string.
    // ** therefore , we will use LCS technique here by 
    // ** using 1 string as it is and other reverse of it.
    
    
    int LCS(string p , string s){
     
        // recursively equations are:
        
        // take : if(p[i]==s[j]) 1 + func(i+1 , j+1 , s , p)
        // not-take: A =  func(i+1 , j , s , p) ,
        // B = func(i , j+1 , s , p) ,
        // C = func(i+1 , j+1 , s , p)
  
        // ans : max(take , not-take = max(A , B , C))
        
        // now in tabulation form
        
        int l1 = p.size() , l2 = s.size();
        
        vector<vector<int>> dp(l1+1 , vector<int>(l2+1 , 0));
        
        for(int i = l1-1 ; i >= 0 ; i--){
            for(int j = l2-1 ; j >= 0  ; j--){
                              
                if(p[i] == s[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                dp[i][j] = max(dp[i+1][j+1] , 
                               max(dp[i][j+1] , dp[i+1][j]));
                }
                
            }
        }
        
        return dp[0][0];
    }
    
    int longestPalindromeSubseq(string s) {
        
        string p = s; // bbbab
        reverse(p.begin() , p.end()); // babbb
        
        int len  = LCS( p  ,  s);
         return len;
    }
};