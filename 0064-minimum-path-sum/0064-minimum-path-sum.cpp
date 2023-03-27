class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
     
        int m = grid.size() , n = grid[0].size();

        vector<vector<int>> ans(m , vector<int>(n , 0));

        ans[0][0] = grid[0][0];
        for(int j = 1 ; j < n ; j++){
            ans[0][j] = grid[0][j] + ans[0][j-1];
        }

        for(int i = 1 ; i < m ; i++){
            ans[i][0] = grid[i][0] + ans[i-1][0];
        }

        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                ans[i][j] = grid[i][j] + min(ans[i][j-1] , ans[i-1][j]);
            }
        }

        return ans[m-1][n-1];
    }
};