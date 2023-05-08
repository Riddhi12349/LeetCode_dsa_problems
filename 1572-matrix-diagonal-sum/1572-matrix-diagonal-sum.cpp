class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i = 0 , j = 0 , n = mat.size();
        int sum = 0;
        for( ; i < n  && j < n  ; i++ , j++){
               sum += mat[i][j];
               mat[i][j] = 0;
        }

        i = 0 , j = n-1;
        for( ; i <= n-1 && j >= 0 ; i++ , j--){
               sum += mat[i][j];
               mat[i][j] = 0;
        }

        return sum;
    }
};