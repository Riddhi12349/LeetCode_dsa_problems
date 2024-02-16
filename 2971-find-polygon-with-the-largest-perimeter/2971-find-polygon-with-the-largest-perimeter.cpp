class Solution {
public:
    using ll = long long;
    long long largestPerimeter(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin() , nums.end());
        
        vector<ll> pref(n , 0);
        
        pref[0] = nums[0];
        
        for(int i = 1 ; i < n ; i++){
            pref[i] = pref[i-1] + nums[i];
        }
        
        for(int i = n-2 ;  i >= 1 ; i--){
            if(pref[i] > nums[i+1])
                return pref[i+1];
        }
            return -1;
    }
};