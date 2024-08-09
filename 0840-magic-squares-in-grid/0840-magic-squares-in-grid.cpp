class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int m = grid.size() , n = grid[0].size();
        
        if(m < 3) return 0;
        if(n < 3) return 0;
        
        int ans = 0;
        
       
        
      for(int i=0 ; i <= m-3 ; i++){
         
         for(int j = 0 ; j <= n-3 ; j++){
             
          int d1sum = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
          int d2sum = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];
       
          int r1sum = grid[i][j] + grid[i][j+1] + grid[i][j+2];
          int r2sum = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
          int r3sum = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
         
          int c1sum = grid[i][j] + grid[i+1][j] + grid[i+2][j];
          int c2sum = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
          int c3sum = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
              
             unordered_map <int,int> mp;
         
             
             for(int k1 = i ; k1 < i+3 ; k1++){
                
                 for(int k2 = j ; k2 < j+3 ; k2++){
                    
                     if(grid[k1][k2] >= 1 && grid[k1][k2] <= 9)
                               mp[grid[k1][k2]]++;
                     
                   //  rsum += grid[k1][k2];
                 }
                
             }
             
          if(mp.size() == 9  && d1sum == d2sum
             && r1sum == r2sum && r2sum == r3sum && r1sum == d1sum 
             && c1sum == c2sum && c2sum == c3sum && c1sum == d1sum){
              ans++;
          }
             
         }
            
     }
        
        return ans;
        
    }
};