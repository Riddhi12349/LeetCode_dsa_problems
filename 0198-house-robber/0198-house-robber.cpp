class Solution {
public:
    int rob(vector<int>& nums) {

       int n = nums.size() , indx = 0; 
      vector<int>  dp(n , 0);
      dp[0] = nums[0];
      for(int i = 1 ; i < nums.size() ; i++){
          if(i == indx + 1){
              dp[i] = max(dp[i-1] , nums[i]);
          }
          else{
              dp[i] = max(dp[i-1] , nums[i] + dp[indx]);
              indx++;
          }
      }
      return dp[n-1];
    }
};