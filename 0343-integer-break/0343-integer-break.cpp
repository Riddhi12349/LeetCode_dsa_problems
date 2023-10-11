class Solution {
public:
    int dp[60];
    
    int find(int n){

        if(n == 0)  return 1;
              
         if(dp[n] != -1) return dp[n];
        
         int  ans = 1;
        
        for(int i = 1 ; i < n ; i++){
              int prod = i * max(n-i , find(n-i));
              ans = max(ans , prod);
          }
            
        return dp[n] = ans;
    }
    
    int integerBreak(int n) {
         
        memset(dp , -1 , sizeof(dp));
        return find(n);
        
    }
};