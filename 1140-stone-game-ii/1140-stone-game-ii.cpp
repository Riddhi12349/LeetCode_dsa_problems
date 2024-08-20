class Solution {
public:
    int dp[105][105][3];
    
    int find(vector<int>& piles , int i , int M , int chance){
        
        int n = piles.size() , ans1 = INT_MIN  , ans2 = INT_MAX; 
        
        if(i >= n ) return 0;
        
        if(dp[i][M][chance] != -1) return dp[i][M][chance];
        
        if(chance == 1){
            
            int score = 0;
            for(int x = 1 ; x <= 2*M; x++){
                if(i+x-1 < n){
                    
                    score += piles[i+x-1];
                    int res = find(piles , i+x , max(M, x) , 0);
                    
                    ans1 = max(ans1, score+res);
                }
            }
            
            return dp[i][M][chance] = ans1;
        }
        
        else{
            
            for(int x = 1 ; x <= 2*M ; x++){
                
                int res = find(piles , i+x , max(M, x) , 1);
                ans2 = min(ans2 , res);
            }
        }
        
        return dp[i][M][chance] = ans2;
    }
    
    int stoneGameII(vector<int>& piles) {
    
        //Chance = 1 => ALICE 
        //Chance = 0 => BOB
        
        memset(dp , -1 , sizeof(dp));
        
        return find(piles , 0 , 1 , 1);
    }
};