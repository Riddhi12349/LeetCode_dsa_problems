class Solution {
public:

    void dfs(vector<vector<char>>& grid , int i , int j){

        int m = grid.size() , n = grid[0].size();

        if( i < 0 || i >= m || j < 0 || j >= n){
            return;
        }

        if(grid[i][j] == '1'){
            grid[i][j] = '0';
        dfs(grid , i+1 , j);
        dfs(grid , i , j+1);       
        dfs(grid , i-1 , j);
        dfs(grid , i , j-1);
        }
    } 

  int numIslands(vector<vector<char>>& grid) {     
      
        int cnt = 0 , m = grid.size() , n = grid[0].size();
          if(m == 0 || n == 0){return 0;}

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == '1'){
                    dfs(grid , i , j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};