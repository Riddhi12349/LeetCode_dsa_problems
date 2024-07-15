class Solution {
public:
    vector<vector<string>> ans;
    
    bool isvalid(int i , int j , int n, vector<vector<char>>& grid){
        
        //checking in same row , and same col no-one present
        
        for(int k = 0 ; k < n ; k++){
            if(grid[i][k] == 'Q') return false;
            if(grid[k][j] == 'Q') return false;
        }
       
        //checking in left diagonal
        for(int rr = i-1 , cc = j-1 ; rr >= 0 && cc >= 0 ; rr-- , cc--){
            if(grid[rr][cc] == 'Q') return false;
        }
        
        for(int rr = i-1 , cc = j+1 ; rr >= 0 && cc < n ; rr--, cc++){
            if(grid[rr][cc] == 'Q')  return false;
        }
        
        return true;
    }
    
    void find(int r , int n , vector<vector<char>>& v1){
        
        if(r >= n){
            
            vector<string> v2;
            
            for(int i = 0 ; i < n ; i++){
                string tmp = "";
                for(int j = 0 ; j < n ; j++){
                    tmp += v1[i][j];
                }
                v2.push_back(tmp);
            }
            
            ans.push_back(v2);
            return;
        }
        
        for(int c = 0 ; c < n ; c++){
            if(isvalid(r , c , n , v1)){
                v1[r][c] = 'Q';
                find(r+1 , n , v1);
                v1[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
       
    vector<vector<char>> v1(n , vector<char>(n , '.'));
        
        find(0,n , v1);
        return ans;
    }
};