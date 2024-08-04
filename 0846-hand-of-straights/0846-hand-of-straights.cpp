class Solution {
public:
    using p = pair<int,int>;

    bool isNStraightHand(vector<int>& hand, int gs) {
        
        int n = hand.size();
        if(n % gs != 0) return false;
        
        unordered_map <int,int> mp; //{ele , freq}
        
        for(auto x : hand){
            mp[x]++;
        }
        
        priority_queue<p,vector<p>,greater<p>> pq;        //min_pq
        
        for(auto x : mp){
            pq.push({x.first , x.second});
        }
        
        while(!pq.empty()){
            
            int cnt = gs;
            int prv = -1;
            
            vector<p> tmp;
            
            while(cnt > 0){
               
                p p1 = pq.top(); 
                pq.pop();
                
                int ele = p1.first , fr = p1.second;
                
               // cout << ele << " " << fr << endl;
                
                if(prv==-1 || ele == prv+1){
                    prv = ele;
                    fr--;
                    if(fr > 0){ tmp.push_back({ele , fr}); }
                }
                else{
                    return false;
                }
                
                cnt--;
            }
            
            for(int i = 0 ; i < tmp.size() ; i++){
                pq.push(tmp[i]);
            }
            
        }
        
        return true;
    }
};