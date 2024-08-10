class Solution {
public:
    void findBits(vector<int>& v1, int num){
        
        int i=0;
        while(num > 0){
            int r = num % 2;
            v1[i] = r;
            i++;
            num = num/2;
        }
        
    }
    int minFlips(int a, int b, int c) {
        
        vector<int> a_bits(32 , 0) , b_bits(32 , 0) , c_bits(32 , 0) , x_bits(32 , 0);

        int x = a|b;
       
        findBits(a_bits  , a);
        findBits(b_bits  , b);
        findBits(c_bits  , c);
        findBits(x_bits  , x);
        
        int ans=0;
        
        for(int i=0; i<32 ;i++){
            if(c_bits[i] == x_bits[i]) continue;
            else{
                if(x_bits[i] == 0){
                    ans++;
                }
                else{
                    if(a_bits[i]==1 && b_bits[i]==1) ans +=2;
                    else ans++;
                }
            }
        }
        
        return ans;
    }
};