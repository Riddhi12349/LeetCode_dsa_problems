class Solution {
public:
    int subarr_with_at_most( int k  , vector<int>& a ){
        
        unordered_map <int,int> mp;
        int ans = 0 , i = 0;
        
        for(int j = 0  ; j < a.size() ; j++){
            
            mp[a[j]]++;
            
            while(i <= j && mp.size() > k){
                 if(--mp[a[i]] == 0){
                        mp.erase(a[i]);
                    }
                  i++;
                }            
        
          ans += (j-i+1);
        
        }
        
        return ans;
        
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int x = subarr_with_at_most( k , nums );
        int y = subarr_with_at_most( k-1 , nums );
        
        return x-y;
    }
};