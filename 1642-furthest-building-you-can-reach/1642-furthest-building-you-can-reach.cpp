class Solution {
public:
    int furthestBuilding(vector<int>& hts, int bricks, int ladders) {
        
        priority_queue<int,vector<int>,greater<int>> min_pq;
        
        int n = hts.size();
        
        for(int i = 0 ; i < n-1 ; i++){
            
            int diff = hts[i+1]-hts[i];
            if(diff <= 0) continue;
            
            if(min_pq.size() < ladders){
                min_pq.push(diff);
            }
            else{
                min_pq.push(diff);
                int t = min_pq.top();
                min_pq.pop();
                bricks -= t;
                if(bricks < 0)
                    return i;
            }
        }
        
        return n-1;
    }
};