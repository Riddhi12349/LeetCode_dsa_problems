class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> vis(n+2 , 0);

        for(int i = 0 ; i < n ; i++){
            vis[edges[i][0]] += 1;
            vis[edges[i][1]] += 1;  
        }
        
        for(int i= 1 ; i < n+2 ; i++){
            if(vis[i]==n) return i;
        }
        return -1;
    }
};