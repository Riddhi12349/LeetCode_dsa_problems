class Solution {
public:
    long helper(vector<int>& coins , int amt , int indx , vector<vector<int>>& dp){
        
        // if(indx >=  coins.size() || amt <= 0){
        //     return (amt == 0) ? 0 : INT_MAX-1;
        // }
        
        if(amt == 0){
            return 0;
        }
        
        if(indx >= coins.size() || amt < 0){
            return INT_MAX-1;
        }

            if(dp[indx][amt] != -1){
                return dp[indx][amt];
            }

            long take = INT_MAX-1;
            if(coins[indx] <= amt){
                 take = 1 +  helper(coins , amt - coins[indx] , indx , dp);
            }
            long notTake = helper(coins , amt , indx + 1 , dp);

            dp[indx][amt] = min(take , notTake);
            return  min(take , notTake);
    }
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amt+1 , -1));
        long ans = helper(coins , amt , 0 , dp);
        if(ans == INT_MAX-1){ return -1; }
        else 
        return ans;
    }
};