class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size() , n = grid[0].size();
        
        int dp[m+1][n+1];
        memset(dp , INT_MAX , sizeof(dp));
        
        for(int i = m-1 ; i >= 0 ; i--){
            for(int j = n-1; j >= 0 ; j--){
                
                if(i==m-1 && j==n-1) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                
                int op1 = INT_MAX , op2 = INT_MAX;
                if(i+1 < m){ op1 = dp[i+1][j]; }
                if(j+1 < n){ op2 = dp[i][j+1]; }
                
                dp[i][j] = grid[i][j]+ min(op1 , op2);
            }
        }
        
        return dp[0][0];
    }
};