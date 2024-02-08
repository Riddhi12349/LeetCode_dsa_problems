class Solution {
public:
    using ll = long long;
    
    int find(ll n , ll t , ll i, vector<vector<ll>>& dp){
        
        if(t == n)
            return 0;
        if(t > n)
            return 1e5;
        if(i>=(ll)(sqrt(n)+1)) 
            return 1e5;
        
        if(dp[t][i] != -1) return dp[t][i];
        
      ll p = 1e5 , q = 1e5 , r = 1e5;
   
       // cout << t << endl;
      if(t+i*i <= n){
        p = 1+find(n, t+i*i , i,dp);
        q = 1+find(n, t+i*i , i+1,dp);
       }
        r = find(n, t , i+1,dp);
        
        return dp[t][i] = min({p,q,r});
       // return min({p,q,r});
    }
    
    int numSquares(int n) {  
       
       ll p = sqrt(n)+1;
       ll n1 = n;
        
       vector<vector<ll>> dp(n1+1,vector<ll>(p,-1));
       int ans = find(n,0,1 , dp);  
       return min(ans,n);
    }
};