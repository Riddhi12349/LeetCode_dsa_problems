class Solution {
public:
    int dp[105][105];
    
    int isPossible(int i , vector<int>& a , int sum , int s, int hi){
        
        int n = a.size();
       // int d = abs(hi-i);
        
        if(i==hi){ return true; }
        
        if(dp[i][hi]!=-1) return dp[i][hi];
        
        int p = 0 , b = 0;
        
        if(sum-a[i] >= s || (hi-i==1))
           p = isPossible(i+1 , a , sum - a[i] , s , hi);
       
        if(sum - a[hi] >= s || (hi-i==1))
           b = isPossible(i , a , sum - a[hi] , s , hi-1);
       
        
        return dp[i][hi] = p|b;
    }
    
    bool canSplitArray(vector<int>& a, int s) {
      
        
        int n = a.size(); int sum  = 0 ; 
        for(auto x  : a) sum += x;
        
        memset(dp,-1,sizeof(dp));
    
        return isPossible(0 , a , sum , s, n-1);    
    }
};