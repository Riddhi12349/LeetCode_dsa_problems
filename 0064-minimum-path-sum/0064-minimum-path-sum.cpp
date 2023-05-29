class Solution {
public:
/****** dp TABLE ********
    int helper(vector<vector<int>>& grid , int i , int j , vector<vector<int>>& dp , int m , int n) {
*/
        /*
    dp[0][0] = grid[0][0];
  for(int j = 1 ; j < n ; j++){
      dp[0][j] = dp[0][j-1] + grid[0][j];
  }
  for(int i = 1 ; i < m ; i++){
      dp[i][0] = dp[i-1][0] + grid[i][0];
  }
     for(int i = 1 ; i < m ; i++){
       for(int j = 1 ; j < n ; j++){
        dp[i][j] = grid[i][j] + min(dp[i-1][j] , dp[i][j-1]);
               }
           }

           return dp[m-1][n-1];
    }
*/
        int helper(vector<vector<int>>& grid , int i , int j , vector<vector<int>>& dp , int m , int n) {
      
        if(i == m-1 && j == n-1){
            return grid[i][j];
        }
        if( i >= m|| j >= n || i < 0 || j < 0){
           // return 201;
            return INT_MAX;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int x = grid[i][j];
   

int p = x + min(helper(grid , i , j+1 , dp , m , n) , helper(grid , i+1 , j , dp , m , n));
        
        dp[i][j] =  p;
        return p;
}
     
    int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size() , n = grid[0].size();
     vector<vector<int>> dp(m , vector<int>(n , -1));   

    // vector<vector<int>> dp(m , vector<int>(n , 0));   
       return helper(grid , 0 , 0 , dp , m , n);
    }
};