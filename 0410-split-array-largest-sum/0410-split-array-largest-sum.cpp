class Solution {
public:
   using ll = long long; 
    
   bool isPoss(ll mid , int k , vector<int>& a){
       
       ll sum = 0 , no_of_subarr = 1;
       
       for(auto x : a){
           if(sum + x <= mid){
               sum += x;
           }
           else{
               no_of_subarr++;
               sum = x;
           }
       }
       
       return no_of_subarr <= k;
   }
    
   int splitArray(vector<int>& a, int k) {
       
        ll low = *max_element(a.begin() , a.end());
        ll high = accumulate(a.begin() , a.end() , 0);
       
        ll ans = -1;
       
        while(low <= high){
            
            ll mid = (low + high)/2;
            
            if(isPoss(mid , k , a)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
       
       return ans;
    }
};