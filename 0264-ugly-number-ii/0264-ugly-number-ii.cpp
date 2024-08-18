class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> dp(n , 0);
        dp[0] = 1; // dp[i] indicates or stores 0th ugly number 
        
        int p2 = 0 , p3 = 0 , p5 = 0;
        
        for(int i=1 ; i < n ; i++){
            
            int twoMultiple = dp[p2]*2; //1*2 =2
            int threeMultiple = dp[p3]*3; //1*3 = 3
            int fiveMultiple = dp[p5]*5; //1*5 = 5
            
            dp[i] = min({twoMultiple , threeMultiple , fiveMultiple});
            
            if(twoMultiple == dp[i]){
                p2++;
            }
            
            if(threeMultiple == dp[i]){
                p3++;
            }
            
            if(fiveMultiple == dp[i]){
                p5++;
            }                
             
        }
        
        return dp[n-1];
        
    }
};