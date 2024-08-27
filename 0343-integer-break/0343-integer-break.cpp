class Solution {
public:
    int dp[65];
    
    int find(int n){
        
        if(n==0) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        int ans = 1;
        for(int i = 1 ; i <= n-1 ; i++){
            ans = max(ans , i*max(n-i , find(n-i)));
        }
        
       return dp[n] = ans;
    }
    int integerBreak(int n) {
       
       memset(dp , -1 , sizeof(dp));
       return find(n);
    }
};