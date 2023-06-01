class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int dx[8] = {1,0,1,-1,-1,-1,0,1};
        int dy[8] = {0,1,1,0,1,-1,-1,-1};
        int n= grid.size();
       if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
		{
			return -1;
		}
        queue<pair<int,int>>q;
        q.push({0,0});

        int step = 0;
        int size = 0;
        while(!q.empty()){

            step++;
            size = q.size();
            while(size--){

                auto front = q.front();
                int x = front.first;
                int y= front.second;
                q.pop();

                if(x == n-1 && y == n-1){
                    return step;
                }
            for(int i = 0 ; i < 8 ; i++){

                int nx = x + dx[i];
                int ny = y + dy[i];

   if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0){
                q.push({nx,ny});
                grid[nx][ny] = 1;
   }
            }
            }
        }
        return -1;
    }
};