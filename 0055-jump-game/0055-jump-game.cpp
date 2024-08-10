class Solution {
public:
    //Recur + Memo
    int dp[10005];
    
    bool find(int curIndx , vector<int>& a){
        
        int n = a.size();
        
        if(curIndx == n-1) return true;
        
        if(curIndx >= n) return false;
        
        if(dp[curIndx] != -1) return dp[curIndx];
        
        int len = a[curIndx];
        
        for(int i=1 ; i<= len ; i++){
            
            int j = curIndx + i;
            if(j < n){
                if(find(j , a) == true){ 
                    return dp[curIndx] = true; 
                }
            }
        }
        
        return dp[curIndx] = false;
    }
    
    bool canJump(vector<int>& a) {
        
       memset(dp , -1 , sizeof(dp));
       return find(0 , a);
        
    }
};