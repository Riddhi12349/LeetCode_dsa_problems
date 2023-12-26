class Solution {
public:
    int N,K,T;
    int dp[32][1002];
    const int mod = 1e9+7;
    
    int find(int d , int t){
        if(d == N){
            if(t == T) return 1;
            return 0;
        }
        
        if(dp[d][t]  != -1) return dp[d][t]%mod;
        
        int w = 0;
        
        for(int i = 1 ; i <= K ; i++){
            w += find(d+1 , t+i)%mod;
            w = w % mod;
        }
        
        return dp[d][t] = w%mod;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        N = n , K = k , T = target ;
        memset(dp,-1,sizeof(dp));
       return find(0,0)%mod;
    }
};