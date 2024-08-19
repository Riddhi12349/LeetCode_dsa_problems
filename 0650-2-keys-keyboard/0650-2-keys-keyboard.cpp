class Solution {
public:
    using ll = long long;
   
    ll findOps(ll curSize , ll prvlen , int n){
        
        if(curSize > n) return 1e6;
        if(curSize == n) return 0;
        
        ll op1 = 1 + findOps(curSize + prvlen , prvlen , n);
        ll op2 = 2 + findOps(curSize + curSize , curSize , n);
            
        return min(op1 , op2);
    }
    
    int minSteps(int n) {
        
        if(n==1) return 0;
        
        ll ans = 2 + findOps(2 , 1 , n);
        
        return ans;
        
    }
};