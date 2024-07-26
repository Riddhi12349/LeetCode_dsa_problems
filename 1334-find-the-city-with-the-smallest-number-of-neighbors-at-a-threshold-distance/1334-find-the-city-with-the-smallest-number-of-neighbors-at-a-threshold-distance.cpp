class Solution {
public:
   
    int findTheCity(int n, vector<vector<int>>& edges, int distThresh) {
        
        vector<vector<int>> dist(n , vector<int>(n , 1e6)); 
              
        //initialize dist matrix
        
        for(int i = 0 ; i < edges.size() ; i++){
            dist[edges[i][0]][edges[i][1]] = edges[i][2];
            dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        
        //apply floyd warshall
        
        for(int k = 0 ; k < n ; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
     
                    dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                 
                }
            }
        }
        
        //print
      /*  for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    */
        
        int city = -1, num = INT_MAX;
        
        for(int i = 0 ; i < n ; i++){
            int cnt = 0;
          
            for(int j = 0 ; j < n ; j++){
                
                if(i != j && dist[i][j] <= distThresh){
                    cnt++;
                }
            }
            
            cout << i << " " << cnt << endl;
            
            if(num >= cnt){ city = i; num = cnt; }
        }
        
        
        return city;
    }
};