class Solution {
public:
    using p = pair<int,double> ;
    
    double maxProbability(int n, vector<vector<int>>& edges, 
                         vector<double>& succProb, 
                         int stNode, int endNode) {
        
        unordered_map <int,vector<p> > mp;
        
        for(int i = 0 ; i < edges.size() ; i++){
            
            int u = edges[i][0] , v = edges[i][1];
            mp[u].push_back({v , succProb[i]});
            mp[v].push_back({u , succProb[i]});
        }
        
        priority_queue<pair<double , int>> pq; 
        //Declaring Max-Pq for [Prob , Node]
        
        vector<double> result(n , 0.0);
        result[stNode] = 1.0;
        
        pq.push({1.0  , stNode});
        
        while(!pq.empty()){
            
            auto p1 = pq.top();
            pq.pop();
            
            int node = p1.second;
            double prob = p1.first;
            
            for(auto adj : mp[node]){
                
                int nbNode = adj.first;
                double  probToReach = adj.second;
                
                if(result[nbNode] < prob*probToReach){
                    result[nbNode] = prob*probToReach;
                    pq.push({result[nbNode] , nbNode});
                }
                
            }
        }
        
        
        return result[endNode];
    }
};