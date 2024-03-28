class Solution {
public:
    //using p = pair<int,int>;
    
    int maxSubarrayLength(vector<int>& nums, int k) {
       
        unordered_map <int,int> mp;
        int n = nums.size();
    //    vector<int> cnt(n , 0);
        
      /*  for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
            cnt[i] = mp[nums[i]];
        }*/
        
        int mxlen = 0, st = 0 ;
       
        for(int end = 0 ; end < n ; end++){
          
            mp[nums[end]]++;
            
            if(mp[nums[end]] > k){
                while(nums[st] != nums[end] && st <= end){
                    mp[nums[st]]--;
                    st++;
                }
                if(nums[st]==nums[end]){ mp[nums[st]]--; st++; }
            }
   
            mxlen = max(mxlen , end-st+1);
        }
        
        return mxlen;
    }
};