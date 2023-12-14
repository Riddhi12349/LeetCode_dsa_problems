class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> diff(m,vector<int>(n,0));
      
        vector<int> row , col ;

        for(int i = 0 ; i < m ; i++){
            int p = 0;
            for(int j = 0; j < n; j++){
                p += grid[i][j];
            }
            row.push_back(p);
        }

        for(int j = 0 ; j < n ; j++){
            int p = 0;
            for(int i = 0 ; i < m ; i++){
                  p += grid[i][j];
            }
           col.push_back(p);
        }
      
       for(int i = 0 ; i < m ; i++){
           for(int j = 0; j < n ; j++){
               int o_r = row[i];
               int oc = col[j];
               int zr = n-o_r;
               int zc = m-oc;
               diff[i][j] = (o_r+oc-zr-zc);
           }
       }
       
        return diff;
    }
};