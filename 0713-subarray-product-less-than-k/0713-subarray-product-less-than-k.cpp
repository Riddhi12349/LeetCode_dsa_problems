class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      
        if(k == 0) return 0;
        
       int j = 0 , n = nums.size(); 
       int prod = 1;
       int ans  = 0;
        
       for(int i = 0 ; i < n ; i++){
            prod = prod*nums[i];
            //if(prod <= k){ ans += (i+1-j); }
           // else{ 
              while(prod >= k && j <= i){
                  prod = (prod/nums[j]);
                  j++;}
            //}
           if(prod < k){
               ans += (i+1-j);}
       }
        
        return ans;
    }
};