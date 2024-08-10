class Solution {
public:
    int dp[502][502];
    
    int find(int i , int j , string word1 , string word2){
        
        int n1 = word1.size() , n2 = word2.size();
        
        if(i >= n1 && j >= n2) return 0;
        
        if(i >= n1){
            return n2-j; //insrt
        }
        
        if(j >= n2){
            return n1-i;  //delete
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(word1[i] == word2[j]){
            return dp[i][j] =  find(i+1 , j+1 ,word1 , word2);
        }
        else{
            
            int insrt = 1 + find(i , j+1 , word1 , word2);
            int del   = 1 + find(i+1 , j , word1 , word2);
            int rep   = 1 + find(i+1 ,j+1 , word1 , word2);
                
             return dp[i][j] = min(insrt , min({del , rep}));
        }
    }
    
    int minDistance(string word1, string word2) {
        memset(dp , -1 , sizeof(dp));
        return find(0 , 0, word1 , word2);
    }
};