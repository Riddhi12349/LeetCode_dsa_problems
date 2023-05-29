class Solution {
public:
/*
    bool helper(vector<int>& nums , int indx , int sum , vector<vector<int>> dp){

        if(indx >= nums.size() || sum <= 0){
            return (sum == 0)? 1 : 0;
        }
        if(dp[indx][sum] != -1){
            return dp[indx][sum];
        }
        bool take = 0;
        if(nums[indx] <= sum){
         take = helper(nums , indx + 1 , sum - nums[indx] , dp);
        }
        bool not_take = helper(nums , indx + 1 , sum , dp);

        return take || not_take;
    }
    */

    bool canPartition(vector<int>& nums) {
     
        int tot_sum = 0 , n = nums.size();
        for(int  i = 0 ; i < nums.size() ; i++){
            tot_sum += nums[i];
        }

        if(tot_sum % 2 != 0){ return false; }

        int s1 = tot_sum / 2;
    //    vector<vector<int>> dp(nums.size() , vector<int>(s1 + 1 , -1));
    //    return helper(nums , 0 , s1 , dp);
       
           vector<vector<int>> dp(nums.size()+1 , vector<int>(s1 + 1 , 0));
            dp[0][0] = 1;
            for(int i = 1 ; i <= nums.size() ; i++){
                for(int j = 1 ; j <= s1 ; j++){
                    if(nums[i-1] > j){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                    }
                }
            }
            return dp[n][s1];  }                       

};