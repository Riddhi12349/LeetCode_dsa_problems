class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size() , n = mat[0].size();
        
        vector<vector<int>> dist(m , vector<int>(n , 0));
        
        queue<pair<int,int>> q;
        
        for(int i=0;  i < m ; i++){
            for(int j=0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        
        int dx[] = {-1 , 1 , 0  , 0};
        int dy[] = {0 , 0  , -1 , 1};
        
        while(!q.empty()){
            
            auto p = q.front();
            q.pop();
            
            int x = p.first , y = p.second;
            
            for(int i = 0 ; i < 4 ; i++){
                
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && nx < m && ny >= 0 && ny < n &&  mat[nx][ny] == 1){
                    q.push({nx,ny});
                    mat[nx][ny]=0;
                    dist[nx][ny] = dist[x][y]+1;
                }
                
            }
                
        }
        
        return dist;
    }
};