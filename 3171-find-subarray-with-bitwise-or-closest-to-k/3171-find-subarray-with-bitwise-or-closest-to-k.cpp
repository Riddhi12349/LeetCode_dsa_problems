class Solution {
public:
    void updateFreq(int operation , int val , vector<int>& freq){
        
        int i=0;
        while(val > 0){
            int r = val % 2;
            if(r == 1){
                freq[i] += operation;
            }
            val= val/2;
            i++;
        }
        
    }
    
    int minimumDifference(vector<int>& nums, int k) {
        
       
        int res = INT_MAX;
        vector<int> freq(32 , 0);
        
        int i=0 , j=0 , n=nums.size()  , OR = 0;
        
        while(j < n){
        
               OR = OR | nums[j];
               updateFreq(1 , nums[j] , freq);
            
               cout << OR <<  endl;   
            
               res = min(res , abs(k-OR));
              
            if(OR < k){
                j++;
                continue;
            }
            else if(OR > k){ //need to increase it
              
              while(OR > k && i < j){
                
                updateFreq(-1 , nums[i] , freq);
              
                //change AND
                OR = 0;
                for(int t = 0 ; t < 32 ; t++){
                    if(freq[t] > 0)
                       OR = OR | (1 << t);
                }
                    
                cout << OR << endl;
                i++; 
                res = min(res , abs(k-OR));
              }
                
            }
            else if(OR == k){
                return 0;
            }
            
           
            j++;
        }
        
        return res;
    }
};