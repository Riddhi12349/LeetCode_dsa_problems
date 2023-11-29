class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
    
        unordered_map<long long,int> mp;
        long long cnt = 0 , ans = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
           long long d = nums[i]-i;
            if(mp.count(d) > 0){ ans += cnt-mp[d];}
            else{ ans += cnt; }
              
            mp[d]++; 
            cnt++;
        }
        
        return ans;
    }
};