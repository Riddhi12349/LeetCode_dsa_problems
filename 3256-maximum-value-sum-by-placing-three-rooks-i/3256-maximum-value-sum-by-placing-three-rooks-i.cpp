class Solution {
public:
    using ll = long long;
    
    ll dp[105][105][105];
    
    ll maxValue(int i , int colRook1 , int colRook2 , vector<vector<pair<ll,ll>> >& v1){
        
        int m = v1.size();
        
        if(i >= m) return -1e12;
        
        ll ans = LONG_LONG_MIN;
       
        if(colRook1 == -1){
           
            //not-pick-i-row-for-rook1
          
            ans = max(ans , maxValue(i+1 , colRook1 , colRook2 , v1));
            
            /*
        ans = max(ans , v1[i][0].first + maxValue(i+1 , arr[i][0].second , colRook2 , v1));
        ans = max(ans , v1[i][1].first + maxValue(i+1 , arr[i][1].second , colRook2 , v1));
        ans = max(ans , v1[i][2].first + maxValue(i+1 , arr[i][2].second , colRook2 , v1));
        */
            
            for(int j = 0 ; j<3 ; j++){
                ans = max(ans , v1[i][j].first + maxValue(i+1 , v1[i][j].second , colRook2 , v1));
            }
      }
       else if(colRook2 == -1){
       
           ans = max(ans , maxValue(i+1 , colRook1 , colRook2 , v1)); //NOT-PICK ITH ROW
           
          /* 
           if(v1[i][0].second != colRook1)
              ans = max(ans , v1[i][0].first + maxValue(i+1 , colRook1 , v1[i][0].second , v1) );
           
           if(v1[i][1].second != colRook1)
               ans = max(ans , v1[i][1].first + maxValue(i+1 , colRook1 , v1[i][1].second , v1));
           
           if(v1[i][2].second != colRook1)
               ans = max(ans , v1[i][2].first + maxValue(i+1 , colRook1 , v1[i][2].second , v1));
           
           */
           
           for(int j = 0 ; j < 3 ; j++){
               
               if(v1[i][j].second != colRook1){
                   ans  = max(ans , v1[i][j].first + maxValue(i+1 ,colRook1, v1[i][j].second , v1)); //PICK ITH ROW
               }
           }
           
       }
       else{
           
           ans = max(ans , maxValue(i+1 , colRook1  , colRook2 , v1));
           
         for(int j = 0 ; j < 3  ; j++){
             
           if(v1[i][j].second != colRook1 && v1[i][j].second != colRook2)
               ans = max(ans , v1[i][j].first);
           
           }
       }
       
        return dp[i][colRook1+1][colRook2+1] = ans;
    }
    
    long long maximumValueSum(vector<vector<int>>& board) {
        
        memset(dp  , -1 ,sizeof(dp));
        
        int m = board.size() , n = board[0].size();
        
        
        vector<vector<pair<ll,ll>>> v1;
        
        for(int i = 0 ; i < m ; i++){
            
            vector<pair<ll,ll>> tmp;
            
            for(int j = 0 ; j < n ; j++){
                tmp.push_back({board[i][j] , j});
            }
            
            sort(tmp.begin() , tmp.end() , greater<pair<ll,ll>>());
            v1.push_back({tmp[0] , tmp[1] , tmp[2]});
            
        }
        
        
        return maxValue(0 , -1, -1 , v1);
        
    }
};