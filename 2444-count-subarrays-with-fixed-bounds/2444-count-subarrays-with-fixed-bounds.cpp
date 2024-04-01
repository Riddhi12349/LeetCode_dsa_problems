class Solution {
public:
    using ll = long long;
    
    ll countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        int n = nums.size();
        vector<ll> cnt(n , 0);
     //   int mn = INT_MAX , mx = INT_MIN;
      
        priority_queue<int,vector<int>,greater<int>> mn_pq;
        priority_queue<int> mx_pq;
        
        unordered_map<int,int> mp;
        
        int j = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > maxK || nums[i] < minK){
                cnt[i] = 0;
                j = i+1;
                mn_pq = priority_queue<int,vector<int>,greater<int>>();
                mx_pq = priority_queue<int>();
                mp.clear();
                continue;
            }
         
            mn_pq.push(nums[i]); mx_pq.push(nums[i]);
            mp[nums[i]]++;
            
            if(mn_pq.top() == minK && mx_pq.top() == maxK){ 
              cnt[i] = ((i-1 >= 0 && cnt[i-1]>0) ?  cnt[i-1] : 1);
              int tmp = 0;
                
              while(j <= i){
                if((nums[j] != minK && nums[j] != maxK) 
                   ||  (nums[j]==minK && mp[nums[j]] > 1) 
                   ||  (nums[j]==maxK && mp[nums[j]] > 1)){
                  if(--mp[nums[j]]<=0){mp.erase(nums[j]); }
                  tmp++; j++;                      
                }
                else{ break; }
              }
                
              cnt[i] += tmp;
            }
       }
        
        ll ans = 0;
        for(auto x: cnt) ans += x;
        
        return ans;
    }
};