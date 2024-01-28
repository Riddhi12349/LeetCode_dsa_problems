class Solution {
public:
    const int mod=1e9+7;
    int dp[1005][1005];
    
    int solve(int n,int k){
       
        if(n==0) return 0;
        if(k==0) return 1;
        
        if(dp[n][k] != -1)
            return dp[n][k];
        
        int ans = 0;
        for(int inv = 0 ; inv <= min(n-1,k) ; inv++){
            ans += solve(n-1,k-inv)%mod;
            ans=ans%mod;
        }
        return dp[n][k] = ans%mod;
    }
    
    int kInversePairs(int n, int k) {
      memset(dp,-1,sizeof(dp));
      return solve(n,k);
    }
};