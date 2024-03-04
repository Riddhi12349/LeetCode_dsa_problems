class Solution {
public:
 
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n = tokens.size();
        sort(tokens.begin() , tokens.end());
        
        int score = 0;
        
        for(int low = 0 , high = n-1 ; low <= high ; ){
            if(power >= tokens[low]){
                power -= tokens[low]; score++; low++;
            }
            else if(power < tokens[low]){
                if(score  >= 1){
                    //option -- to inc power or not
                    //advt if 
                    if((low+1 < high)
                       && 
              (tokens[high]+power) >= (tokens[low])){
                        
                        power += tokens[high];
                        power -= tokens[low];
                        high--; low+=1;
                    }
                    else{
                        return score;
                    }
                }
                else{
                    return score;
                }
            }
        }
        
        return score;
    }
};