class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        int n = nums.size();
        
        map <vector<int>,int> mp;
        vector<int> pref(n+1,0);
        
        for(int i=0 ; i < n ; i++){
           
            pref[i+1]=pref[i];
            
            if(nums[i] % p == 0)
                pref[i+1] += 1;
        }
        
       // int cnt = 0;
        for(int i= 0 ; i < n ; i++){
            
            vector<int> v1;
            
            for(int j= i ; j < n ; j++){
                v1.push_back(nums[j]);
                if(pref[j+1]-pref[i] <= k){
                    mp[v1]++;
                   // cnt++;
                }
            }
          //  mp[nums[i]]++;
        }
        
       // cnt-=n; cnt+= mp.size();
        return mp.size();
    }
};