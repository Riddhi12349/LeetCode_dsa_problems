class Solution {
public:
    using ll = long long;
    long long maximumImportance(int n, vector<vector<int>>& roads) {
       //node=>  0,1,2,3,4
       //times=> 2,3,4,2,1
        
        vector<ll> times(n,0);
        
        for(int i=0 ; i < roads.size() ; i++){
            times[roads[i][0]]++;
            times[roads[i][1]]++;
        }
        
        priority_queue<pair<ll,ll>> pq;
        for(int i=0 ; i < n; i++){
            pq.push({times[i] , i});
        }
        
        vector<ll> val_assign(n,0);
        int t=n;
        while(!pq.empty()){
            auto p = pq.top(); pq.pop();
            val_assign[p.second] = t;
            --t;
            
        }
        
        ll ans = 0;
        for(int i = 0 ; i < roads.size() ; i++){
            ans += val_assign[roads[i][0]];
            ans += val_assign[roads[i][1]];
        }
            
        return ans;
        
    }
};