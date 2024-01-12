class Solution {
public:
    using ll=long long;
    
    bool isvalid(int n ,int div1, int div2 , int cnt1, int cnt2){
        ll lcm = (((ll)div1*div2)/((ll)__gcd(div1,div2)));
        int inv = n/lcm;
        int inv_d1 = n/div1 - inv;
        int inv_d2 = n/div2 - inv;
        
        int free = n-inv_d1-inv_d2-inv;
        
        if(cnt1-inv_d2 > 0)
            free -=( cnt1-inv_d2);
        if(cnt2-inv_d1 > 0)
            free -=( cnt2-inv_d1);
        
        return free>=0;
    }
    int minimizeSet(int div1, int div2, int cnt1, int cnt2) {
        ll l = 1 , h = 2e9, ans=INT_MAX;
        
        while(l <= h){
            
            ll m = (l + h)/2;
            if(isvalid(m,div1,div2,cnt1,cnt2)){
                ans = min(ans, m);
                h = m-1;
            }
            else 
               l = m+1;
        }
        
        return ans;
    }
};