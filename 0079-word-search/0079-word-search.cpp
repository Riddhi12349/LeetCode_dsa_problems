class Solution {
public:
    bool find(int i , int j , int str_i , vector<vector<char>>& board ,
             string& word){
        
        if(str_i >= word.size())  return true;
        
        int m = board.size() , n = board[0].size();
        
        if(i >= m || j >= n || i < 0 || j < 0){
            return false;
        }
        
        if(board[i][j] == word[str_i]){
            
            char ch = board[i][j];
            
            board[i][j] = '#';
            
            bool p = find(i+1 , j , str_i+1 , board , word);
            bool q = find(i , j+1 , str_i+1 , board , word);
            bool r = find(i-1 , j , str_i+1 , board , word);
            bool t = find(i , j-1 , str_i+1 , board , word);
            
            board[i][j] = ch;
            
            if(p || q || r || t){
                return true;
            }
            
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size() , n = board[0].size();
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == word[0]){
                      if(find(i, j, 0, board , word)){ return true; }
                }
            }
        }
        
        return false;
    }
};