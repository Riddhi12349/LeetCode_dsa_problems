class Solution {
public:
    using ll = long long;
    ll dp[2002][1002][2];
    
    const int mod = 1e9+7;
   
    int find(int st , int end , int steps , int k , int isneg){     
      
       if(steps == k) {
           if(st == end) return 1;
           return 0;
       }
 
       if(dp[abs(st)][steps][isneg] != -1)
            return dp[abs(st)][steps][isneg];
       
       isneg = (st+1) < 0 ? 1: 0;
       int w1 = find(st+1 , end , steps + 1 , k , isneg);
        
       isneg = (st-1) < 0 ? 1 : 0;
       int w2 = find(st-1 , end , steps + 1 , k , isneg);
        
       isneg = st < 0 ? 1 : 0;
        return dp[abs(st)][steps][isneg] = (w1 + w2)%mod;
    }
    
    int numberOfWays(int st , int end, int k) {
        
      //  memset(dp , -1 , sizeof(dp));
        for(int i = 0 ; i < 2002 ; i++)
            for(int j = 0 ; j < 1002 ; j++)
                for(int k = 0 ; k < 2 ; k++)
                    dp[i][j][k]=-1;
        
        int steps = 0;
        return find(st , end , steps , k,1);
    }
};