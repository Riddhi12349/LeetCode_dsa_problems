class Solution {
public:
  int N;
  const int MOD = 1e9 + 7;
  int dp[101][101][101];

  int solve(int i , int pr , int people , int minProfit , vector<int>& group, vector<int>& profit) {


  if(people > N){
      return  0;
  }
  if(i == group.size()){
      if(pr < minProfit){ 
          return  0;
     }
      return  1;
  }
   
  if(dp[i][pr][people] != -1){
      return dp[i][pr][people];
  }
  long long take = solve(i+1 , min(pr + profit[i] , minProfit) , people + group[i] , minProfit , group , profit);
  long long not_take = solve(i+1 , pr , people , minProfit , group , profit);

  return  dp[i][pr][people] = (take%MOD + not_take%MOD)%MOD;
  }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        N = n;
        memset(dp , -1 , sizeof(dp));
        return solve(0,0,0,minProfit , group , profit);
    }
};