class Solution {
public:
    int dp[100005];
    
    bool find(vector<int>& a , int i){
        
        int n = a.size();
        
        if(i >= n) return true;
        
        if(dp[i] != -1) return dp[i];
        
        if(i+2 < n && a[i]==a[i+1]&&a[i+1]==a[i+2]){
           dp[i] = find(a , i+3);
            if(dp[i]) return true;
        }
        if(i+1 < n && a[i]==a[i+1]){
            dp[i] = find(a , i+2);
            if(dp[i]) return true;
        }
        if(i+2 < n && (a[i+1]-a[i])==1 &&
           (a[i+2]-a[i+1])==1){
           dp[i] = find(a , i+3);
               if(dp[i]) return true;
        }
        
        return false;
    }
    bool validPartition(vector<int>& a) {
       memset(dp , -1 , sizeof(dp)); 
       return  find(a , 0);
    }
};