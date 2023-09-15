class Solution {
public:
    using P = pair<int,int>;
      int v = 0;
    int primAlgo(vector<vector<P>>& adj){
        
        priority_queue<P,vector<P> , greater<P> > pq; // forming min-pq
        
        //{weight , node}
        pq.push({0,0});
        
        vector<bool> inMST(v , false);
     
        int sum = 0; //computing minimum sum value 
                     //by iterating over all vertices
        
        while(!pq.empty()){
            
            auto p = pq.top();
            pq.pop();
            
            int wt = p.first;
            int node = p.second;
            
            if(inMST[node] == true)
                continue;
            
            inMST[node] = true;
            sum += wt;
            
            for(auto tmp : adj[node]){
                
                int neighbor = tmp.first;
                int dist = tmp.second;
               
                if(inMST[neighbor] == false)
                {
                    pq.push({dist , neighbor});
                }
            }
        }
        
        
        return sum;
        
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
         v = points.size();
        vector<vector<P>> adj(v);
        
        for(int i = 0 ; i < v ; i++){
       
           int x1  = points[i][0];
           int y1 = points[i][1];
            
            for(int j = i+1 ; j < v ; j++){
                
                int x2 = points[j][0];
                int y2 = points[j][1];
               
                int d = abs(x1-x2) + abs(y1-y2);
                
                adj[i].push_back({j , d});
                adj[j].push_back({i , d});
            }
        }
        
        return primAlgo(adj);
      }
    };