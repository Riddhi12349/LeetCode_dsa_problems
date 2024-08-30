class Solution {
    vector<int> parent , size;
    
    int findUPar(int node){
        
        if(node == parent[node]) return node;
        
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int node_i , int node_j){
        
        int ulp_i = findUPar(node_i);
        int ulp_j = findUPar(node_j);
        
        if(ulp_i == ulp_j) return;
        
        if(size[ulp_i] > size[ulp_j]){
            parent[ulp_j] = ulp_i;
            size[ulp_i] += size[ulp_j];
        }
        else{
            parent[ulp_i] = ulp_j;
            size[ulp_j] += size[ulp_i];
        }
        
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        
        //dsu CONCEPT
        
        int n = stones.size();
        parent.resize(n+1 , 0);
        size.resize(n+1 , 1);
        
        for(int i=0 ; i < n ; i++){
            parent[i] = i;
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    unionBySize(i , j);
                }
                
            }
        }
        
        
        int groups = 0;
        
        for(int i = 0 ; i < n ; i++){
            if(parent[i] == i)  groups++;
        }
        
        int remove = n-groups;
        return remove;
    }
};