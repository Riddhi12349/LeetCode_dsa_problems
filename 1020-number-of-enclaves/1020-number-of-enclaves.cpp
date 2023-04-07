class Solution {
public:

  int dfs(vector<vector<int>>& grid , int r , int c) {
      int m = grid.size(), n = grid[0].size();
      if(r >= m || c >= n || r < 0 || c < 0){
          return 0;
      }
      if(grid[r][c] == 0){
          return 0;
      }
      if(grid[r][c] == 1){
          grid[r][c] = 0;
    
    int x =  dfs(grid , r , c+1);
    int y =  dfs(grid , r+1 , c);
    int z =  dfs(grid , r-1 , c);
    int p =  dfs(grid , r , c-1);
    return x + y + z + p + 1;
      }
      return 0;
  }
  void boundary_check(vector<vector<int>>& grid , int r , int c) {
    
     int m = grid.size(), n = grid[0].size();
      if(r < 0 || c < 0 || r >= m || c >= n){
          return;
      }
      if(grid[r][c] == 0){
          return ;
      }
      if(grid[r][c] == 1){
      grid[r][c] = 0;
    
      dfs(grid , r , c+1);
      dfs(grid , r+1 , c);
      dfs(grid , r-1 , c);
      dfs(grid , r , c-1);  
      }
  }
    int numEnclaves(vector<vector<int>>& grid) {

        int m  = grid.size() , n = grid[0].size();
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
 if(grid[i][j] == 1 && (i == 0 || j == 0 || i == m-1 || j == n-1)){
                 boundary_check(grid , i , j);
             }
        }
    }
    int no_of_lands = 0;
      for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
            if(grid[i][j] == 1){
             no_of_lands += dfs(grid , i , j);
               
                }
            }
        }
    return no_of_lands;
        }
};