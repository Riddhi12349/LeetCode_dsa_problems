class Solution {
public:
    void dfs(int r , int c , vector<vector<char>>& board , vector<vector<char>>& ans){
        
        int m = board.size() , n = board[0].size();
        
        if(r < 0 || c < 0 || r >= m || c >= n || board[r][c] == 'X') return;
        
        if(ans[r][c] == 'O' ) return;
        
        ans[r][c] = 'O';
        
        dfs(r+1 , c , board , ans);
        dfs(r , c-1 , board , ans);
        dfs(r , c+1 , board , ans);
        dfs(r-1 , c , board , ans);
    }
    
    void solve(vector<vector<char>>& board) {
        
        int m = board.size() , n = board[0].size();
        
        vector<vector<char>> ans(m, vector<char>(n , 'X'));
        
        for(int i=0 ; i < m ;  i++){
           if(board[i][0] == 'O'){
               dfs(i ,0 , board , ans);
           }
           if(board[i][n-1] == 'O'){
               dfs(i , n-1 , board , ans);
           }
        }
        
        for(int j=0; j < n ; j++){
            if(board[0][j] == 'O'){
                dfs(0 , j , board , ans);
            }
            if(board[m-1][j] == 'O'){
                dfs(m-1 , j, board , ans);
            }
        }
        
        board = ans;
    }
};