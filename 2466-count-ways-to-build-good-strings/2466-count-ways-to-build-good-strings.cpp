class Solution {
public:
    int Z , O;
    const int mod = 1e9+7;
    int dp[100005];
    
    int find(int len){
        
        if(len == 0) return 1;
        if(len < 0) return 0;
        
        if(dp[len] != -1) return dp[len];
        
        int op1 = find(len-Z);
        int op2 = find(len-O);
        
        return dp[len] = ((op1%mod + op2%mod)%mod) ;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        
        Z = zero ; O = one;
        memset(dp , -1 , sizeof(dp));
        
        int ans = 0;
        for(int i = low ; i <= high ; i++){
            ans += (find(i)%mod);
            ans = ans%mod;
        }
        return ans;
    }
};