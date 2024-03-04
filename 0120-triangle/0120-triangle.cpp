class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        int n = triangle[m-1].size();
        
        int dp[m+1][n+1];
        memset(dp , INT_MAX , sizeof(dp));
        
        for(int i = m-1 ; i >= 0 ; i--){
            for(int j = 0 ; j <= i; j++){
                
                if(i==m-1){
                    dp[i][j] = triangle[i][j]; 
                    continue;
                }
                
                int op1 = dp[i+1][j]; int op2 = INT_MAX;
                if(j+1 <= i+1) 
                    op2 = dp[i+1][j+1];
                
                dp[i][j] = triangle[i][j]+min(op1,op2);
            }
        }
        
        return dp[0][0];
    }
};