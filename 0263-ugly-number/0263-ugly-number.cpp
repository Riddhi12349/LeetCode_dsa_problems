class Solution {
public:
 
    bool isUgly(int n) {
        
        if(n <= 0)
            return false;
        
        if( n == 1)
            return true;
        
        for(int i = 2 ; i < 6 && n > 1 ; i++){
            
            while(n > 1 && n % i == 0)
                n = n/i;
        }
        
        return n == 1;
    }
};