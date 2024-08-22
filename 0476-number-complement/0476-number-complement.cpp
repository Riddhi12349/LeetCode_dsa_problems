class Solution {
public:
    int findComplement(int num) {

        
        int ans = 0 , i = 0 ;
        
        while(num){
            int d = num % 2;
            if(d == 0){
                ans = ans + pow(2,i);
            }
           i++;
           num = num/2;
        }
        
        return ans;
    }
};