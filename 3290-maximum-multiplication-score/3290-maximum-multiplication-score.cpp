class Solution {
public:
    using ll = long long;
   // ll dp[5][100005];
/*
    ll find(int i , int j ,  vector<int>& a , vector<int>& b){
        
        if(i >= 4) return 0;
        if(j >= b.size()) return -1e10;

        if(dp[i][j] != -1) return dp[i][j];

        ll pick = 1ll*a[i]*b[j] + find(i+1 , j+1 , a , b);
        ll notPick = find(i , j+1 , a , b);

        return  dp[i][j]  = max(pick , notPick);
    }
    */
    long long maxScore(vector<int>& a, vector<int>& b) {
        
      //  memset(dp , -1e8 , sizeof(dp));
       // return find(0 , 0, a , b);
      
      int n = b.size();
        
      vector<vector<ll>> dp(5 , vector<ll>(n+1 , -1e12));
       
      for(int j=0; j<=b.size(); j++)
          dp[4][j]=0;
        
        for(int  i=3 ; i >=0 ; i--){
            for(int  j = b.size()-1 ; j >= 0 ; j--){
               
               ll pick = 1ll*a[i]*b[j] + dp[i+1][j+1];
               ll notpick = dp[i][j+1];
                
               dp[i][j] = max(pick , notpick);
                
            }
        }
        
        return dp[0][0];
    }
};