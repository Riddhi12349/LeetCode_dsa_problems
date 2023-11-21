class Solution {
public:
    const int mod = 1e9+7;
    int rev(int a){
        
        int t = 0; //a=972
        while(a != 0){
            int p = a % 10; //2
            t = t*10 + p; //2
            a = a/10;  //97
        }
        return t;
    }
    
    int countNicePairs(vector<int>& nums) {
      
        int n = nums.size();
        vector<int> diff(n,0);
        
        for(int i = 0 ; i < n ; i++){
            int t = rev(nums[i]);
            diff[i] = nums[i]-t;
        }
        
        int ans = 0;
        
        unordered_map<int,int> mp;
        
        for(int i = 0 ; i < n ; i++){
           if(mp.count(diff[i]) > 0){
               ans += mp[diff[i]];
               ans = ans % mod;
           }
            mp[diff[i]]++;
        }
        
        ans = ans % mod;
        return ans;        
    }
};





