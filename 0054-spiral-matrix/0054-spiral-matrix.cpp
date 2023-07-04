class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size() , n = matrix[0].size();

        int top = 0 , bottom = m-1;
        int left = 0 , right = n-1;
        int dir = 0;
        vector<int>ans;

        while(ans.size() < m*n){
          if(dir == 0){
              for(int j = left ; j <= right ; j++){
                  ans.push_back(matrix[top][j]);
              }
              top++;
          }
          
          else if(dir == 1){
             for(int j = top ; j <= bottom ; j++){
                 ans.push_back(matrix[j][right]);
             }
             right--;
          }

          else if(dir == 2){
              for(int j = right ; j >= left ; j--){
                  ans.push_back(matrix[bottom][j]);
              }
              bottom--;
          }

          else if(dir == 3){
              for(int j = bottom ; j >= top ; j--){
                  ans.push_back(matrix[j][left]);
              }
              left++;
          }
          dir = (dir+1)%4;
        }

        return ans;
    }
};