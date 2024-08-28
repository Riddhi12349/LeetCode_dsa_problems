class Solution {
public:
    bool dfs(int r , int c , vector<vector<int>>& grid2 ,
             vector<vector<int>>& grid1 ,
             vector<vector<int>>& vis){
        
        int m = grid2.size() , n = grid2[0].size();
        
        if(r < 0 || c < 0 || r >= m || c >= n 
            || vis[r][c] == 1 || grid2[r][c] == 0){ 
              return true;
        }
           
        if(grid2[r][c] == 1 && grid1[r][c] == 0){
            return false;
        }
           
           vis[r][c] = 1;
           
          bool a = dfs(r+1 , c , grid2 , grid1 , vis);
          bool b = dfs(r-1 , c , grid2 , grid1 , vis);
          bool p = dfs(r , c-1 , grid2 , grid1 , vis);
          bool d = dfs(r , c+1 , grid2 , grid1 , vis);
           
           return a & b & p & d;
    }
    
    int countSubIslands( vector<vector<int>>& grid1,                                    vector<vector<int>>& grid2) {
     
        int m = grid2.size() , n = grid2[0].size();
        
        vector<vector<int>> vis(m , vector<int>(n , 0));
    
        int cnt = 0;
        
        for(int i = 0 ; i < m ; i++){
            for(int j=0 ; j < n ; j++){
                if(grid2[i][j] == 1 && vis[i][j] == 0){
                    if(dfs(i , j , grid2 , grid1 , vis)  == true)
                        cnt++;
                }
            }
        }
        
        
        return cnt;
    }
};