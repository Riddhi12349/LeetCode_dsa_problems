class Solution {
public:
  int find(int i , vector<int>& st , vector<int>& dp, vector<vector<int>>& jobs){
        
        int n = st.size();
        
        if(i >= n) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int nxt  = lower_bound(st.begin(),st.end(),jobs[i][1])-st.begin();
        
        int pick = jobs[i][2] + find(nxt , st, dp ,jobs);
        int notPick = find(i+1 , st , dp , jobs);
        
        return dp[i] = max(pick , notPick);
    }
    
    
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& pf) {
     
     int n = st.size();
     
      vector<vector<int>> jobs(n);
      vector<int> dp(n+1,0);
        
     for(int i = 0 ; i < n  ; i++)
         jobs[i] = {st[i] , et[i] , pf[i]};
     
     sort(jobs.begin() , jobs.end());
     sort(st.begin() , st.end());
        
      int mx = -1; 
     for(int i = n-1; i >= 0 ; i--){
         
         int nxt = lower_bound(st.begin()+i , st.end() , 
                              jobs[i][1]) - st.begin();
         
         int pick = jobs[i][2] + dp[nxt];
         int notpick = dp[i+1];
         
         dp[i] = max(pick  , notpick);
         
         mx = max(mx , dp[i]);
     }
  //   int mx_profit = find(0 , st , dp , jobs);

    // return mx_profit;
        return mx;
 }
};