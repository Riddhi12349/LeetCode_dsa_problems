class Solution {
public:
    
    int findTurns(int i , int j , string& s , vector<vector<int>>& dp){
        
         if(i==j) return 1;
          
         if(dp[i][j] != -1){
             return dp[i][j];
         }
        
         int mnTurns = INT_MAX;
         
         for(int k=i ; k < j ; k++){
             
         
             mnTurns = min(mnTurns ,
                           findTurns(i , k , s , dp)+findTurns(k+1 , j , s , dp));
         }
        
         if(s[i] == s[j]) mnTurns -= 1;
       
         return dp[i][j]  = mnTurns;
    }
    
    int strangePrinter(string s) {
        
        int n = s.size();
   
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
        return findTurns(0 , n-1 , s , dp);
    }
};