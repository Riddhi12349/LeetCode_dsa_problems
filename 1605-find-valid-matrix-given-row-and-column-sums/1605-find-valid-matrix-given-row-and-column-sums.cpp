class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        int m = rowSum.size() , n = colSum.size();
        
        vector<vector<int>> mat(m , vector<int>(n , 0));
        
        int i = 0 , j = 0;
        
        while(i < m && j < n){
            
            if(rowSum[i] > colSum[j]){
                mat[i][j] = colSum[j];
                rowSum[i] -= colSum[j];
                j++;
            }
            else if(rowSum[i] < colSum[j]){
               mat[i][j] = rowSum[i];
               colSum[j] -= rowSum[i];
               i++;
           }
           else{
              mat[i][j] = rowSum[i];
              i++; j++;
          }
        }
        
        return mat;
    }
};