class Solution {
public:

    int helper(vector<int>& cuts_2 , int i , int j , vector<vector<int>>& dp){

        if(i > j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int mini = INT_MAX;
        for(int k = i ; k <= j ; k++){
int cost = (cuts_2[j+1]-cuts_2[i-1]) + helper(cuts_2 , i, k-1 , dp) + helper(cuts_2 , k+1 , j , dp);
    mini = min(mini , cost);
        }
        dp[i][j] = mini;
        return mini;
    }
    int minCost(int n, vector<int>& cuts) {
        
        vector<int> cuts_2;
        cuts_2.push_back(0);
        for(int i = 0  ; i < cuts.size() ; i++){
            cuts_2.push_back(cuts[i]);
        }
        cuts_2.push_back(n);
        sort(cuts_2.begin() , cuts_2.end());
        int p = cuts.size();
        vector<vector<int>> dp(p+1 , vector<int>(p+1 , -1));
    return  helper(cuts_2 , 1 , cuts_2.size()-2 , dp);
    }
};