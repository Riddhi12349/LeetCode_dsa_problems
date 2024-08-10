class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int flips = 0;
        
        while(a > 0 || b > 0 || c > 0){
            
            int r1 =  a % 2 , r2 = b % 2 , r4 = c % 2;
            
            if(r1 == 0 && r2 == 0 && r4 == 1){
                flips++;
            }
            else if(r1 == 1 && r2 == 0 && r4 == 0){
                flips++;
            }
            else if(r1 == 0 && r2 == 1 && r4 == 0){
                flips++;
            }
            else if(r1 == 1 && r2 == 1 && r4 == 0){
                flips += 2;
            }            
              
            a = a/2; b  = b/2; c = c/2;
        }
        
        return flips;
    }
};