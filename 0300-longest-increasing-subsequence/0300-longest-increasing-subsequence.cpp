// MERE = TC -> O(N^2), SC -> O(N^2)
// CAN BE SOLVED IN :
//= TC -> O(N^2) , SC -> O(N)
//= TC -> O(NLOGN) , SC -> O(1) USING BINARY SEARCH****
class Solution {
public:
/****** (SOLN-1) *********
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
    */

 /****** (SOLN-2) *******
    int lengthOfLIS(vector<int>& nums){
       
        int n = nums.size();
        vector<int> dp(n ,  0);
        dp[0] = 1;
     
        for(int i = 1 ; i < n ; i++){
            int maxim = 0;
            for(int j = i-1 ; j >= 0 ; j--){
                if(nums[i] > nums[j]){
                    if(maxim < dp[j]){ maxim = dp[j];}
                }
            }
            dp[i] = maxim + 1;
        }

        int ans_max = 0;
        for(int i = 0 ; i < n ; i++){
            if(ans_max < dp[i]){
                ans_max = dp[i];
            }
        }
        return ans_max;
    }
    */

    /****** (SOLN-3) *******/

     int lengthOfLIS(vector<int>& nums){
         vector<int> temp;
         temp.push_back(nums[0]);

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
    auto indx = lower_bound(temp.begin() , temp.end() , nums[i]); // iterator
    temp[indx - temp.begin()] = nums[i];
            }
        }
        return temp.size();
     }
};