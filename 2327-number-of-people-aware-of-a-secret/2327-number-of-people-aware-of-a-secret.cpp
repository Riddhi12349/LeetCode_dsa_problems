class Solution {
public:
    const int mod = 1e9+7;
    int N , D, F;
    vector<int> dp;
    
    int find(int st){
    
        if(st > N) return 0;
        
        if(dp[st] != -1) return dp[st];
        
        int ans = 1;
        
       for(int i = st+D ; i <= st+F-1  ; i++){
           ans +=  find(i)%mod;
           ans  =  ans % mod;
        }
      
        if(N >= F+st) ans -=1;
     
        //  cout << "day="<< st <<" " << "persons=" << ans <<endl ;     
        return dp[st]= ans % mod;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        N = n  ; D = delay ; F = forget;
        dp = vector<int>(n+1,-1);
        return find(1);
    }
};