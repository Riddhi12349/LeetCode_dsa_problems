class Solution {
public:
    using ll = long long;
    
    ll countSubarrays(vector<int>& nums, int k) {
      
        int n = nums.size();
        vector<ll> pref(n , 0);
        
        int mx = *max_element(nums.begin(), nums.end());
        
        for(int i = 0 ; i < n ; i++){
            if(i>0) pref[i]=pref[i-1];
            if(nums[i] == mx){
                pref[i] +=1;
            }
        }
        
        vector<ll> cnt(n, 0); int j = 0;
        for(int i = 0 ; i < n ; i++){
            int tmp = 0;
            while(j <= i && 
                  ((j==0 && pref[i]>=k) || 
                   (j>0 && pref[i]-pref[j-1] >= k))){
                tmp++;
                j++;
            }
            if(i>0) cnt[i] = cnt[i-1];
            cnt[i]+= tmp;
        }
        
        ll ans=0;
        for(auto x : cnt) ans+=x;
        return ans;
    }
};