class Solution {
public:
    using V = vector<int>;
    
    int minTimeToReach(vector<vector<int>>& moveTime) {
        
        //REACH FROM START (0,0) To END (M-1,N-1) IN MIN-TIME => APPLY 'DIJKSTRA ALGORITHM' 
        
        int m  = moveTime.size() , n = moveTime[0].size();
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        vector<vector<int>> dist(m , vector<int>(n , INT_MAX));
       
        //MIN-HEAP
        priority_queue<V,vector<V>,greater<V>> mnPq;
        
        mnPq.push({0 , 0 , 0}); // { TIME, ROW , COLM }
        dist[0][0] = 0;
        
        while(!mnPq.empty()){
            
            auto vec = mnPq.top();
            mnPq.pop();
            
            int time = vec[0] , r = vec[1] , c = vec[2];
            
            if(r == m-1 && c == n-1) return time;
            
            for(int i = 0 ; i < 4 ; i++){
                
                int nr = r + dx[i] , nc = c + dy[i];
                
                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    
                    if(moveTime[nr][nc] <= time && dist[nr][nc] > time+1){
                        dist[nr][nc] = time + 1;
                        mnPq.push({time + 1 , nr , nc});
                    }
                    else if(moveTime[nr][nc] > time){
                        if(dist[nr][nc] > moveTime[nr][nc] + 1){
                            dist[nr][nc] = moveTime[nr][nc] + 1;
                            mnPq.push({dist[nr][nc] , nr , nc});
                        }
                    }
                }
            }
            
        }
        
        
        return dist[m-1][n-1];
        
    }
};