class Solution {
public:
    using p = pair<int,int>;
    
    int findLeastNumOfUniqueInts(vector<int>& a, int k) {
       
        map <int,int> mp;
        priority_queue<p,vector<p>,greater<p>> min_pq;
        
        for(int  i = 0 ; i < a.size()  ; i++){
            mp[a[i]]++;
        }
       
        for(auto it : mp){
            min_pq.push({it.second , it.first});
        }
        
      while(k > 0 && !min_pq.empty()){
         
         auto f = min_pq.top();
         min_pq.pop();
         
         int freq = f.first-1 , ele = f.second;
          if(freq> 0) min_pq.push({freq,ele});
          k--;
      }
        
       int ans = 0;
       while(!min_pq.empty()){
           auto it = min_pq.top();
           ans++;
           min_pq.pop();
       }
        
        return ans;
    }
};