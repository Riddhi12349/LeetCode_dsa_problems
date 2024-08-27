class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>> ans = image;
        
        int m = image.size() , n = image[0].size();
        
        vector<vector<int>> vis(m , vector<int>(n , 0));
        
        int dx[] = {-1, 1 , 0 ,0};
        int dy[] = {0, 0, -1 , 1};
        
        queue<pair<int,int>> q;
        q.push({sr , sc});
        vis[sr][sc] =1;
        
        while(!q.empty()){
            
            auto p = q.front();
            q.pop();
            
            int x = p.first , y = p.second;
            ans[x][y] = color;
            
            for(int i = 0 ; i < 4 ; i++){
               
                int nx = x + dx[i] , ny = y + dy[i];
               
                if(nx >= 0 && nx < m && ny >= 0 && ny < n 
                   && image[nx][ny] == image[sr][sc]  && vis[nx][ny] == 0 ){
                    
                    q.push({nx , ny});
                    vis[nx][ny] = 1;
                }
            }
            
            
        }
        
        return ans;
        
    }
};