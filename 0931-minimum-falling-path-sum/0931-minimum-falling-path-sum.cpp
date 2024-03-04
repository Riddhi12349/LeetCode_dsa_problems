class Solution {
public:
    //******NO FIXED STARTING PNT AND NO FIXED ENDING POINT
    int find(int i , int j , int m , int n , vector<vector<int>>& mat){
        
        if(i >= m || i < 0 || j >= n ||  j < 0)
            return INT_MAX;
        
        if(i==m-1) return mat[i][j];
        
        int op1 = find(i+1 , j , m , n , mat);
        int op2 = find(i+1 , j-1 , m, n, mat);
        int op3 = find(i+1 , j+1 , m , n, mat);
        
        return min({op1 , op2 ,op3})+ mat[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
       
        int m = mat.size() , n = mat[0].size();
      /*  
        //recursion--
        int mn = INT_MAX;
        for(int  j = 0 ; j < n ; j++)
           mn = min(mn , find(0,j,m,n,mat));
        
        return mn;
        */
        
        //TABULATION ----
        
        int dp[m+1][n+1];
        memset(dp , INT_MAX , sizeof(dp));
        
        for(int i = m-1; i >= 0 ; i--){
            for(int j = 0 ; j < n ; j++){
                
                if(i==m-1){
                    dp[i][j] = mat[i][j]; continue;
                }
                
                int op1=INT_MAX , op2=INT_MAX, op3=INT_MAX;
              
                if(j-1 >= 0) op1 = dp[i+1][j-1];
                if(j+1 < n) op2 = dp[i+1][j+1];
                op3 = dp[i+1][j];
                
                dp[i][j] = mat[i][j]+ min({op1, op2 , op3});
            }
        }
        
       int mn=INT_MAX;
        for(int j = 0 ; j < n ; j++)
            mn = min(mn , dp[0][j]);
       return mn;
    }
};