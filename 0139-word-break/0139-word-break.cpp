class Solution {
public:
 #include <unordered_map>
   
int wordBreakHelper(string s,unordered_map<string,int> map ,int indx , vector<int>& dp){

    if(indx == s.size()){
        return 1;
    }
    if(dp[indx] != -1){ return dp[indx]; }

    for(int i = indx ; i < s.size() ; i++){
        string s1 = s.substr(indx , i+1-indx);
        if(map.count(s1) > 0){
            bool ans = wordBreakHelper(s , map ,  i+1 , dp);
            if(ans == 1){
            dp[indx] = ans;
            return ans;
        }
    }
}
    
    dp[indx] = 0;
    return dp[indx];
}
    bool wordBreak(string s, vector<string>& wordDict) {
     
     unordered_map <string , int> map;
     for(int i = 0 ; i < wordDict.size() ; i++){
         map[wordDict[i]] += 1;
     }
     int n = s.size();
     vector<int> dp(n , -1);
     return  wordBreakHelper(s  , map , 0 , dp);   

    }
};