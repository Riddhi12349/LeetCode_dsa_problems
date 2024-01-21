class Solution {
public:
    int dp[105];
    
    int find(int i , vector<int>& a){
        
        if(i >= a.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int t = a[i] + find(i+2, a);
        int p = find(i+1 , a);
        
        return dp[i]= max(t,p);
    }
    
    int rob(vector<int>& a) {
        
        int n = a.size();
        memset(dp , -1 , sizeof(dp));
        
        return find(0,a);
    }
};