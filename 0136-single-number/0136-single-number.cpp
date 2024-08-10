class Solution {
public:
    int singleNumber(vector<int>& a) {
        
        int xor_val = 0;
        for(auto x : a){
            xor_val ^= x;
        }
        
        return xor_val;
    }
};