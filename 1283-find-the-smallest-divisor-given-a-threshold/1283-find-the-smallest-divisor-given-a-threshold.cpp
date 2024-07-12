class Solution {
public:
    using ll = long long ;
    
    ll find(ll div , vector<int>& a){
        
        ll sum = 0;
        
        for(auto x : a){
            sum += (x/ div)+ (x % div !=0);
        }
        
        return sum;
    }
    int smallestDivisor(vector<int>& a , int thr_s) {
        
        int low=1 , high = 1e6 , ans = -1;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            
            ll sum = find(mid , a);
            
            if(sum > thr_s){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1; //decreasing the divisor, b/c we need smallest divisor(A.T.Qs) satisfying sum <= thr_s
            }
        }
    
       return ans;
    }
};