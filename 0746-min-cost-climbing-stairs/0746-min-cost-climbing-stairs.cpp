class Solution {
public:
    int dp[1002];
    int find(int indx , vector<int>& cost){
        
        if(indx >= cost.size()){
            return 0;
        }
        
        if(dp[indx] != -1) return dp[indx];
        
        int c1 = cost[indx] + find(indx + 2 , cost);
        int c2 = cost[indx] + find(indx + 1 , cost);
        
        return dp[indx] =  min(c1 , c2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
       /* 
        int c1 = find(0 , cost);
        int c2 = find(1 , cost);
        
        return min(c1 , c2);
        */
        memset(dp , -1,  sizeof(dp));
        cost.insert(cost.begin() , 0);
        return find(0 , cost);
    }
};