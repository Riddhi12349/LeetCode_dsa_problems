class Solution {
public:
    vector<vector<int>> bridges;
    int timer = 1;
    
    void find(int src , int parent, vector<int>& tin , vector<int>& tlow , vector<int>& vis , int n, 
             vector<int> adj[]){
        
        vis[src] = 1; tin[src] = timer; tlow[src] = timer;
        timer++;
        for(auto neighbor : adj[src]){
            if(neighbor == parent) continue;
            
            if(!vis[neighbor]){
              find(neighbor , src, tin , tlow , vis, n , adj);
            
             tlow[src] = min(tlow[src] , tlow[neighbor]);
                
            if(tlow[neighbor] > tin[src])
                  bridges.push_back({src , neighbor});    
        }
            else {
           // if already visited, then there is no qs of bridge--
         // b/c by some other path that node has been visited
            tlow[src] = min(tlow[src] , tlow[neighbor]);
        }
    }
    }
    vector<vector<int>> criticalConnections(int n, 
                              vector<vector<int>>& conn) {
        
     vector<int> tin(n , INT_MAX) , tlow(n ,INT_MAX) , vis(n , 0);
     
     vector<int> adj[n];
     for(int i=0 ; i < conn.size() ; i++){
         adj[conn[i][0]].push_back(conn[i][1]);
         adj[conn[i][1]].push_back(conn[i][0]);
     }
        
     find(0 , -1 ,tin , tlow, vis , n , adj);
     return bridges;
       
    }
};