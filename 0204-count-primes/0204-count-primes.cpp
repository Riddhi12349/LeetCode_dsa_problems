class Solution {
public:
    
   // bool isPrime(int n){
        
   //     for(int i = 2 ; i <= sqrt(n) ;i++)
    //     if(n%i==0) return 0;
    //     return 1;
    //}
    int countPrimes(int n) {
        
        vector<bool> a(n+1);
        
        for(int i = 2 ; i <= n ; i++)
            a[i] = true;
    
        for(int i = 2 ; i <= n/2 ; i++)            
          //  if(isPrime(i))
            if(a[i] == true)
                for(int j = i*2 ; j <= n ; j+=i)
                    a[j] = false;
            
        int cnt = 0;
        for(int i = 2 ; i < n ; i++)
            if(a[i] == true)
                cnt++;
        
          return cnt;       
    }
};