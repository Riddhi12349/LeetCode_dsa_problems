class Solution {
public:
    bool Prime[1000000];
    
    void isPrime(){
        
        memset(Prime, true,sizeof(Prime));
        
        for(int i = 2 ; i*i <= 1e5 ; i++){
            if(Prime[i]){
                for(int j = i*i ; j <= 1e5 ; j+= i)
                    Prime[j] = false;
            }
        }
    }
    
    vector<int> findPrimeFactors(int n){
        
        vector<int> factors;
        
        while(n % 2 == 0){
            int p = 2;
            factors.push_back(p);
            n = n/2;
        }
        
        for(int i = 3 ; i*i <= n  ; i += 2){
            while(n % i == 0){
                factors.push_back(i); 
                 n  = n/i;
            }
        }
        if(n>=2) factors.push_back(n);
        
        return factors;
    }
    
    int smallestValue(int n) {
       
        isPrime();
        
        while(Prime[n] == false){
            
            vector<int> factors = findPrimeFactors(n);
            
            int sum = 0;
            for(auto f : factors) sum += f;
            
            if(sum == n) return n;
            n = sum;
        }
        return n;
    }
};