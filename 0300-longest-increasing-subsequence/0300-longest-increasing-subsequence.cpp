// MERE = TC -> O(N^2), SC -> O(N^2)
// CAN BE SOLVED IN :
//= TC -> O(N^2) , SC -> O(N)
//= TC -> O(NLOGN) , SC -> O(1) USING BINARY SEARCH****
class Solution {
public:
    int helper(vector<int>& v1 , int n , int i , int prv , vector<vector<int>>& dp){
			if(i >= n){ 
				return 0;
			}
			if(dp[i][prv] != -1){ 
				return dp[i][prv];
			}
     int p = 0;
    if(v1[prv] < v1[i]){
    p = 1 + helper(v1 , n , i+1 , i , dp);
		}
	 int q = helper(v1 , n , i+1 , prv , dp);

	 return dp[i][prv] = max(p,q);
		}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
				vector<int> v1(n+1 , -10001);
				for(int i = 0 ;  i < n ; i++){
					v1[i+1] = nums[i];
				}
     
		 vector<vector<int>> dp(n+1,(vector<int>(n+1 ,-1)));
		 return helper(v1 , n+1 , 1 , 0 , dp);
	
    }
};