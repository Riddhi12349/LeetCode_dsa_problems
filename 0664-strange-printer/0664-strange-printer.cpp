class Solution {
public:
 int dp[100][100];

 int find(int i , int j , string& s){    
  
  if(i == j){ return 1; }

  if(dp[i][j] != -1){
      return dp[i][j];
  }   

  int ans = INT_MAX;
  for(int k = i ; k < j ; k++){
  ans = min(ans , find(i , k , s) + find(k+1 , j , s));
   }
  if(s[i] == s[j]){   ans -= 1; }

  return dp[i][j] = ans;
 } 

    int strangePrinter(string s) {
        
        memset(dp , -1 , sizeof(dp));
        int ans = INT_MAX; int n = s.size();
        ans = min(ans , find(0 , n-1 , s));
        return ans;
    }
};