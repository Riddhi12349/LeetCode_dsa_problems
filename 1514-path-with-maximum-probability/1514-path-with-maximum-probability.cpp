class Solution {
public:
    using  p = pair< double,int >;
    
    double maxProbability(int n, vector<vector<int>>& edges, 
                          vector<double>& succProb, 
                          int stNode, int endNode) {
        
        unordered_map <int,vector<p>> mp;
        
        for(int i = 0 ; i < edges.size() ; i++){
         
            int u = edges[i][0] , v = edges[i][1];
            mp[u].push_back({succProb[i] , v});
            mp[v].push_back({succProb[i] , u});
        }
        
        priority_queue<p> pq; //{ Prob , Node} // prob = probability to reach this starting from th startNode
        
        vector<double> result(n , 0.0);
        result[stNode] = 1;
        
        pq.push({1 , stNode});
        
        while(!pq.empty()){
            
            auto p1 = pq.top();
            pq.pop();
            
            int node = p1.second;
            double prob = p1.first;
            
            for(auto adj : mp[node]){
                
                int nbNode = adj.second;
                double probToReach = adj.first;
                
                if(result[nbNode] < probToReach*prob){
                    result[nbNode] = probToReach*prob;
                    pq.push({result[nbNode] , nbNode});
                }
                
            }
        }
        
        
        return result[endNode];
    }
};