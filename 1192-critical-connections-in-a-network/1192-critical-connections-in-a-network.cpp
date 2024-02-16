class Solution {
public:
    int timer = 1;
    vector<vector<int>> bridges;
    
    void dfs(int src , int parent , vector<int>& tin, vector<int>& tlow ,  vector<int>& vis, vector<vector<int>>& adj){
         
        vis[src] = 1;  tin[src] = timer ; tlow[src] = timer;
        timer++;
        
        for(auto adj_el : adj[src]){ 
            if(adj_el == parent) continue; //impt_step**********
            if(!vis[adj_el]){  
                dfs(adj_el , src , tin, tlow , vis, adj);              
                tlow[src] = min(tlow[src] , tlow[adj_el]);
                if(tlow[adj_el] > tin[src]){
                    bridges.push_back({src, adj_el});
                }
            }
            else{
                tlow[src] = min(tlow[src] , tlow[adj_el]);
            }
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < conn.size() ; i++){
            adj[conn[i][0]].push_back(conn[i][1]);
            adj[conn[i][1]].push_back(conn[i][0]);
        }
        
        vector<int> tin(n ,INT_MAX) , tlow(n, INT_MAX) , vis(n , 0);
        
        dfs(0,-1,tin,tlow,vis,adj);
        return bridges;
    }
};