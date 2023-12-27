class Solution {
public:
 //   "bbbbaaaabbbaa"
 //   [2436164258425] 
    int minCost(string colors, vector<int>& time) {
        
        int ans = 0;
        
        for(int i = 0 ; i < colors.size() ; ){
            
           priority_queue<int,vector<int>,greater<int>> pq;
           pq.push(time[i]);
           
           char ch = colors[i];
           i++; int f = 0;
            
           while(colors[i] == ch){
               pq.push(time[i]); i++; f=1;
           }
           
            if(f==1){ 
                while(pq.size() > 1){
                    ans += pq.top(); pq.pop();
                }
        }
        }
        return ans;
    }
};