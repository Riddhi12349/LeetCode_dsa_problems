class Solution {
public:
    bool isPossible(long long n,long long div1,long long div2,int cnt1,int cnt2){
        
           long long p =(long long) __gcd(div1,div2);
           long long lcm = ((long long)(div1*div2))/p;

           long long both_invalid = n/lcm;
           long long arr1_invalid = n/div1 - both_invalid;
           long long arr2_invalid = n/div2 - both_invalid;
          
           long long can_be_in_any =  n - arr1_invalid - arr2_invalid - both_invalid;

           if(cnt1 > arr2_invalid) {
              can_be_in_any -= (cnt1-arr2_invalid);
           }
           if(cnt2 > arr1_invalid){
               can_be_in_any -= (cnt2 -  arr1_invalid);
           }
           return (can_be_in_any >= 0);
    }

    int minimizeSet(int div1, int div2, int cnt1, int cnt2) {
         
          long long low = 1 , high = 2e9 , ans = INT_MAX;

           while(low <= high){

               long long mid = (low + high)/2;

               if(isPossible(mid,div1,div2,cnt1,cnt2)){
                   ans = min(ans,mid);
                   high = mid-1;
               }
               else{
                   low = mid+1;
               }
            
           }

           return ans;
    }
};