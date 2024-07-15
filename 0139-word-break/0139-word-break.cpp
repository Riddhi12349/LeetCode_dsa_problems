class Solution {
public:
    unordered_map <string,int> mp;
    int dp[1005];
    
    int find(int i , string s){
        
        if(i >= s.size()) return true;
        
        if(dp[i] != -1) return dp[i];
        
        int n = s.size();
        
        for(int j = i ; j < n ; j++){
            
            string tmp = s.substr(i , j-i+1);
            
            if(mp[tmp] > 0){
                
                if(find(j+1 , s)){ return dp[i] = 1; }
            }
        }
        
        return dp[i] = 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
       
        for(auto x : wordDict) mp[x]++;
        
        memset(dp , -1 , sizeof(dp));
        
        return find(0 , s);
    }
};