class Solution {
public:
    using ll = long long;
   // ll dp[100005];
    /*
    ll find(int i , vector<int>& a){
        
        int n = a.size();
        
        if(i >= n-1) return 0;
        
        if(dp[i] != -1) return dp[i];
            
        ll mxscore = 0;
        
        for(int j = i+1 ; j < n ; j++){
            
            ll score = 1ll*(j-i)*a[i] + find(j , a);
            mxscore = max(mxscore , score);
            
        }
        
        return dp[i] = mxscore;
    }
    */
    
    long long findMaximumScore(vector<int>& a) {
        
     //   memset(dp , -1 , sizeof(dp));
     //   return find(0 , nums);
     
         ll score = 0;
         int st_i = 0 , n = a.size();
        
         for(int j = 1 ; j < n ; j++){
             if(a[j] > a[st_i]){
                 score += 1ll*(j-st_i)*a[st_i];
                 st_i = j;
             }
         }
       
        if(st_i != n-1){
            score += 1ll*(n-1-st_i)*a[st_i];
        }
        return score;
    }
};