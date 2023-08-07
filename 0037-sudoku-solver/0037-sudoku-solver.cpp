class Solution {
public:

 bool isValid(vector<vector<char>>& board , int row , int col , char t){
        
        for(int i = 0 ; i < 9 ; i++){
            if(board[row][i] == t) return false;
            if(board[i][col] == t) return false;
      if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == t) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] == '.'){
                    for(char t = '1' ; t <= '9' ; t++){
                        if(isValid(board , i , j , t)){
                          board[i][j] = t;
                          bool aageSoln = solve(board);
                          if(aageSoln == true){ return true;  }
                          else{ board[i][j] = '.' ;}
                        }
                    }
                    return false;//***********
                }



            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};