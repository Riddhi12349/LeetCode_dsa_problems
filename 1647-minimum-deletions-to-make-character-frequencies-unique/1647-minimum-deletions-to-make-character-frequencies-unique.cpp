class Solution {
public:
    int minDeletions(string s) {
        
        unordered_map<char,int> mp;
        for(int i = 0 ; i < s.size() ; i++){
            mp[s[i]]++;
        }
/*      
        mp = { a = 4  , b = 2 , c = 4 -3, x = 4 -2, d = 6 ,  }
        
         3 -> 2, 2 -> 1 , mx_freq = 6 , del=8 --9
      */
        int mx_freq = INT_MIN;
        unordered_map<int,int> fmp;
        for(auto x : mp){
            fmp[x.second]++;
            mx_freq = max(mx_freq , x.second);
        }
        
        vector<int> vis(mx_freq + 1 , 0); 
        int del = 0;
       
      priority_queue<int> pq;
        for(auto x : fmp){
            if(vis[x.first] == 0){
                vis[x.first] = 1;
                x.second -= 1;
            }            
                while(x.second !=  0){
                    pq.push(x.first);
                    x.second -=1;
                }     
        }
        
     for(int i = vis.size()-1 ; i >= 1 && !pq.empty() ; i--){
            if(vis[i]== 0 && pq.top() >= i){
                del += pq.top()-i;
                pq.pop();
            }
        }
         
        while(!pq.empty()){
            del += pq.top();
            pq.pop();
        }
        return del;
    }
};