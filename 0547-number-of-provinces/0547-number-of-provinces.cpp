class Solution {
public:

    void dfs(vector<vector<int>>& isConnected , vector<int>& vis, int i){
        
        int n = isConnected.size();

        if( i > n  || vis[i] == 1){
            return ;
        }

       vis[i] = 1;

       for(int t = 0 ; t < n ; t++){
         if(isConnected[i][t] == 1 && vis[t] == 0)
          dfs(isConnected , vis , t);   
       }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
       vector<int> vis(n ,0);

        int ans = 0;
        for(int i = 0 ; i < n ; i++){
                if(vis[i] == 0){
                    ans++;
                   dfs(isConnected , vis , i);
                }
            }
        return ans;
    }
    
};