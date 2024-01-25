class Solution {
public:
    int dp[1005][1005];
    
    int find(int i, int j, string t1, string t2){
        
        if(i >= t1.size() || j >= t2.size())
            return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(t1[i]==t2[j]){
            return dp[i][j] = 1 + find(i+1,j+1,t1,t2);
        }
        else{
            int p = find(i,j+1,t1,t2); 
            int q = find(i+1,j,t1,t2);
            return dp[i][j] = max(p,q);
        }
    }
    
    int longestCommonSubsequence(string t1, string t2) {
        
        memset(dp,0,sizeof(dp));
  //      return find(0,0,t1,t2);
        int ans = 0;
        
        int n1 = t1.size() , n2 = t2.size();
       
        for(int i = n1-1 ; i>=0 ; i--){
            for(int j = n2-1 ; j>=0 ; j--){
              
                if(t1[i]==t2[j])
                    dp[i][j] = 1+dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i][j+1] , dp[i+1][j]);
                
                ans = max(ans , dp[i][j]);
            }
        }
        
        return ans;
    }
};