class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.size();
        priority_queue<string ,vector<string>,greater<string> > mn_pq;
        
        for(int i = 0 ; i < n ; i++){
            
            int cnt = 0 , p ;
            
            for( p = i ; p  < n ; p++){
                if(s[p]=='1') cnt++;
                if(cnt == k) break;
            }
            
            if(cnt >= k){
              string tmp = s.substr(i , p-i+1);
              mn_pq.push(tmp);
            }
            
        }
        
        if(mn_pq.empty()) return "";
        
        string tmp = mn_pq.top();
        mn_pq.pop();
        
        while(!mn_pq.empty()){
           if(tmp.size() > mn_pq.top().size()){
               tmp = mn_pq.top();
             }
            mn_pq.pop();    
        }
        
        return tmp;
      
      //  return "";
    }
};