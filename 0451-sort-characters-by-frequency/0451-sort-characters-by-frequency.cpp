class Solution {
public:
    using p = pair<int,int>;
    
    string frequencySort(string s) {
      
       string ans = "";
       
       priority_queue <p,vector<p>,greater<p>> min_pq;
       unordered_map <int,int> mp;
        
       for(auto x: s) mp[x]++;
        
       for(auto x : mp){ min_pq.push({x.second,x.first}); }
       
       while(!min_pq.empty()){
           
           auto it = min_pq.top(); min_pq.pop();
           char ch = it.second; int f = it.first;
           
           while(f > 0){
             ans += it.second; f--;}
       }
        
       reverse(ans.begin(), ans.end());
       
       return ans;
    }
};