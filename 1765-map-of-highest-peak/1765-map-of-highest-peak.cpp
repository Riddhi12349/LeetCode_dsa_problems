class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int m = isWater.size() , n = isWater[0].size();
        vector<vector<int>> ans(m,vector<int>(n,INT_MAX));
        queue <pair<int,int>> q;
        
            
        for(int i=0 ; i < m ; i++){
            for(int j=0 ; j<n ; j++){
               
                if(isWater[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
                    
            }
        }
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        
        while(!q.empty()){
            
            pair<int,int> f = q.front();
            q.pop();
            
            int x = f.first , y = f.second;
            isWater[x][y]=1;
            
            for(int i=0 ; i<4 ; i++){
                
                int nx = x + dx[i] , ny = y + dy[i];
                if(nx>= 0 && ny >= 0 && nx < m && ny < n && isWater[nx][ny] != 1){
                    ans[nx][ny]= min(ans[nx][ny],ans[x][y]+1);
                   isWater[nx][ny]=1;
                    q.push({nx,ny});
                 }
            }
        }
        
        return ans;
    }
};