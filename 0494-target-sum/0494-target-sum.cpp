class Solution {
public:
    int dp[25][2500];
    
    int find(int i , int sum , vector<int>& nums, int target){
        
        int n = nums.size();
        
        if(i == n){
            if(sum == target) return 1;
            return 0;
        }
        
        if(sum >= 0 && dp[i][sum] != -1)
            return dp[i][sum];
        else if(sum < 0 && dp[i][sum+1001] != -1) 
            return dp[i][sum+1001];
            
      //  if(dp[i][sum] != -1) return dp[i][sum];
        
        int op1 = 0, op2 = 0;
        
        
        op1 = find(i+1 , sum + nums[i] , nums, target); //add +
        
        op2 = find(i+1 , sum - nums[i] , nums, target); //add -
            
        if(sum >= 0) return dp[i][sum] = op1+op2;
        else return dp[i][sum+1001] = op1+op2;
        
        //return op1 + op2;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        memset(dp , -1 , sizeof(dp));
        
        return find(0,0,nums,target);
    }
};