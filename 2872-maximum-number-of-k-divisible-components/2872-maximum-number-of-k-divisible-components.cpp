class Solution {
public: 
    int find(int curNode, int parNode , int& comp, 
             vector<vector<int>>& adj , vector<int>& values, int k){

        int sum=0;

        for(auto nb : adj[curNode]){
            if(nb != parNode){
                sum += find(nb,curNode, comp, adj , values , k);
            }
        }
        
        sum += values[curNode];
        if(sum % k == 0) comp+=1;
        
        sum %= k;
        
        return sum;
  
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        vector<vector<int>> adj(n+1);

        for(int i = 0 ; i < n-1 ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int comp=0;
        find(0,-1,comp,adj, values, k);
        
        return comp;
    }
};

