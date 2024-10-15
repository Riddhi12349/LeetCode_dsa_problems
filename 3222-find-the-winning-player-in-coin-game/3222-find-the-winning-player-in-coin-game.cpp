class Solution {
public:
    string losingPlayer(int x, int y) {
        
        int p = y*10/40;
        
        if(p > x){
            if(x % 2 == 0){
                return "Bob";
            }
            else{
                return "Alice";
            }
        }
        else{
            if(p % 2 == 0){
                return "Bob";
            }
            else{
                return "Alice";
            }
        }
    }
};