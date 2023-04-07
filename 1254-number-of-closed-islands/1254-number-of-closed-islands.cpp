class Solution {
public:
 
   int dfs(vector<vector<int>>& grid , int row , int col){
        int m = grid.size() , n = grid[0].size();
        if(row >= m || col >= n || row < 0 || col < 0){
            return false;
        }
        if(grid[row][col] == 1){ return true; }
        if(grid[row][col] == 0){
            //check
        
        grid[row][col] = 2;
      bool a1 =  dfs(grid , row+1 , col);
      bool a2 =  dfs(grid , row , col+1);
      bool a3 =  dfs(grid , row-1 , col);
      bool a4 =  dfs(grid , row , col-1);
      return (a1 && a2 && a3 && a4);
        }
        return true;
    }
    int closedIsland(vector<vector<int>>& grid) {
   //     dfs(grid , 1 , 1);
         int m = grid.size() , n = grid[0].size() , cnt = 0;
    for(int i = 1 ; i < m-1 ; i++){
        for(int j = 1 ; j < n-1 ; j++){
            if(grid[i][j] == 0){
                if(dfs(grid , i , j)){  cnt++; }
            }
        }
    }

    return cnt;
    }
};