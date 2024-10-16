class Solution {
public:
    using p = pair<int,char>;
    
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<p> pq;
        
        if(a>0)pq.push({a , 'a'}); 
        if(b>0)pq.push({b , 'b'}); 
        if(c>0)pq.push({c , 'c'});
       
        string ans = "";
        
        while(!pq.empty()){
            
            p p1 = pq.top();
            pq.pop();
            
            char curCh = p1.second; int curfreq = p1.first;
            
            //check
            int n = ans.size();
            
            if(n >= 2 && ans[n-1] == ans[n-2] && ans[n-1] == curCh){
                
                if(pq.empty()) break;
                
                p p2 = pq.top(); 
                pq.pop();
                
                char nxtCh = p2.second; int nxtfreq = p2.first;
                
                //push_back cur
                pq.push({curfreq , curCh});
                
                curCh = nxtCh;  curfreq = nxtfreq;
            }
            
            ans += curCh;
            curfreq -= 1;
            
            if(curfreq > 0){
                pq.push({curfreq , curCh});
            }
            
        }
        
        return ans;
        
    }
};