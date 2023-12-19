class Solution {
public:
 bool isValid(int x, int y, int m , int n){
     if(x >= 0 && x < m && y >= 0 && y < n) return true;
     return false;
 }

 vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

  int dx[] = {1 , 1, 0, -1, -1 , 0, 1, -1};
  int dy[] = {1 , 0, 1, 0, 1 , -1, -1, -1};
  
  int  m = img.size() , n = img[0].size();
  vector<vector<int>> ans(m , vector<int>(n,0));

  for(int i = 0; i < m ; i++){
      for(int j = 0 ; j < n ; j++){
          
          int x = i , y = j;
          int  sum = img[i][j] , cnt = 1;

          for(int k = 0 ; k < 8 ; k++){
            int nx = x + dx[k] , ny = y + dy[k];
            if(isValid(nx,ny,m,n)){ 
                sum += img[nx][ny]; cnt++; }
          }
          
          ans[i][j] = floor(sum/cnt) ;
 //  cout << i << " " << j << " " << ans[i][j] << endl;
      }
  }

  return ans;
    }
};