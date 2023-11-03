class Solution {
public:
    using ll = long long; 
    //[1,1,1,2,3,1,1,1,2,3]
    
    ll find(int remTarget , vector<int>& a){
        
        vector<int> b(a.begin() , a.end());
        for(int i = 0 ; i < a.size() ; i++)
            b.push_back(a[i]);
        
       ll sum = 0;
       ll mnlen = INT_MAX;
        unordered_map <ll , ll> mp;
     
        for(ll i = 0 ; i < b.size() ; i++){
            sum += b[i];
            ll t = sum-remTarget;
            if(mp.count(t) > 0){
                ll l = i-mp[t];
                mnlen = min(mnlen , l);
            }
            mp[sum] = i;
        }
        
        return mnlen;
    }
    int minSizeSubarray(vector<int>& nums, int target) {
        
        ll sum = 0;  int  n = nums.size();
        for(auto i : nums)
            sum += i;
        
        if(sum == target)
           return n;
        else if(target % sum == 0)
            return (n*(target/sum));
        else{
            int N =  target/sum;
            int extra = target % sum;
            
            ll short_len = find(extra , nums);
            
            if(short_len == INT_MAX) return -1;
            return n*N + (int)short_len;
        }
    }
};