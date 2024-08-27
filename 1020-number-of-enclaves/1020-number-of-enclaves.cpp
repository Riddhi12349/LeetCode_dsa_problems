class Solution {
public:
    void dfs(int r , int c , vector<vector<int>>& vis, vector<vector<int>>& grid){
     
        int m=grid.size() , n = grid[0].size();
        
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0) return;
        
        if(vis[r][c] == 1) return;
        
        vis[r][c] = 1;
        
        dfs(r+1 , c , vis , grid);
        dfs(r , c+1 , vis ,grid);
        dfs(r, c-1, vis , grid);
        dfs(r-1 , c , vis, grid);
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size() , n = grid[0].size();
        
        vector<vector<int>> vis(m , vector<int>(n , 0));
        
        for(int i=0 ; i < m ; i++){
            if(grid[i][0] == 1) dfs(i , 0 , vis , grid);
            if(grid[i][n-1] == 1) dfs(i , n-1 , vis, grid);
        }
        
        for(int j=0 ; j < n ; j++){
            if(grid[0][j] == 1) dfs(0 , j , vis , grid);
            if(grid[m-1][j] == 1) dfs(m-1 , j , vis , grid);
        }
        
        int cnt=0;
        
        for(int i=0; i<m ; i++){
            for(int j=0; j<n ;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){ cnt++;}
            }
        }
        
        return cnt;
    }
};