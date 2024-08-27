class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size() , n = grid[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0; i < m ; i++){
            for(int j= 0; j < n ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        int time = 0;
        
        int dx[] = {-1, 1 , 0, 0};
        int dy[] = {0, 0 , -1, 1};
        
        while(!q.empty()){
            
            int s = q.size();
            time++;
            
            for(int i=1 ; i <= s;  i++){
                
                auto p = q.front();
                q.pop();
                
                int r = p.first , c = p.second;
              
                for(int i=0 ; i<4; i++){
                    int nr = r + dx[i] , nc = c + dy[i];
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        q.push({nr , nc});
                        grid[nr][nc] = 2;
                    }
                }
            }
            
            
        }
        
        for(int i= 0 ; i < m ; i++){
            for(int j=0 ; j < n ; j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time-1 >= 0 ? time-1  : 0;
    }
};