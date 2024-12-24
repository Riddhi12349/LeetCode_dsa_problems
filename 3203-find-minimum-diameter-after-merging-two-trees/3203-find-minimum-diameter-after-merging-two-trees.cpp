class Solution {
public:
    void formGraph(vector<vector<int>>& adj , vector<vector<int>>& edges , int n){
        
        for(int i = 0 ; i < n ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
    }
    
    pair<int,int> findExtremes(int srcNode , vector<vector<int>>& adj){
        
        //we will apply bfs to find the farthest Node from the source node
        
        unordered_map <int,int> visNodes;
        
        pair<int,int> p1; 
        int d = 0 , targetNode = srcNode;
        
        queue<int> q;
        q.push(srcNode); visNodes[srcNode]++;
        
        while(!q.empty()){
            
            int s = q.size();
            
          for(int i=1 ; i <= s ; i++){
              
            int fr = q.front();
            q.pop();
                   
            for(auto nb : adj[fr]){
                 if(visNodes.count(nb) == 0){
                     targetNode = nb;
                     q.push(nb);
                     visNodes[nb]++;
                 }
            }
              
          }
            
            if(!q.empty()) d++;
            
        }
        
        return {targetNode , d};
    }
    
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
        int n1 = edges1.size() , n2 = edges2.size();
        
        vector<vector<int>> adj1(n1+1) , adj2(n2+1);
        
        formGraph(adj1 , edges1 , n1);
        formGraph(adj2 , edges2 , n2);
        
        
        auto p1 =  findExtremes(0,adj1);
        auto p2 =  findExtremes(p1.first,adj1);
        
        int diameter1 = p2.second;
        
        p1 = findExtremes(0,adj2);
        p2 = findExtremes(p1.first,adj2);
        
        int diameter2 = p2.second;
        
        return max({diameter1 , diameter2 , ((diameter1+1)/2 + (diameter2+1)/2 + 1)});
        
    }
};