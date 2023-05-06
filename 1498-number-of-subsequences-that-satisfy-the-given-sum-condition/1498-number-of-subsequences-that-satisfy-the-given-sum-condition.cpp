class Solution {
public:
  
    const int MOD = 1e9+7;

    int numSubseq(vector<int>& nums , int target){
        int ans = 0 , n= nums.size();
        vector<int> power(n , 1);
        for(int i = 1 ; i < n ; i++){
            power[i] = (power[i-1] * 2)%MOD;
        }
        sort(nums.begin() , nums.end());
        int i = 0 , j = n-1;
        for( ; i < n ; i++){
            
            int p = target - nums[i]; //6
            if(p < nums[i]){ ans = ans %MOD; return ans;  }
            while(nums[j] > p){
                j--;
            }
            
            int x = j-i;
            ans = (ans%MOD + power[x]%MOD)%MOD ;
          
        }  
        return ans % MOD; 
    }
};