class Solution {
public:
    vector<int> findLIS(vector<int>& arr){
        
        int n = arr.size(); 
        vector<int> LIS(n , 1);
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(arr[j] < arr[i]){
                    LIS[i] = max(LIS[i] , LIS[j] + 1);
                }
            }
        }
        
        return LIS;
    }
    
    vector<int> findLDS(vector<int>& arr){
        
        int n = arr.size();
        vector<int> LDS(n , 1);
        
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = i+1 ; j < n ; j++){
                if(arr[i] > arr[j]){
                    LDS[i] = max(LDS[i] , LDS[j] + 1);
                }
            }
        }
        
        return LDS;
    }
    
    int minimumMountainRemovals(vector<int>& nums) {
        
        vector<int> LIS = findLIS(nums);
        vector<int> LDS = findLDS(nums);
        
        int mnRemovals = INT_MAX  ,  N = nums.size();
        
        for(int i = 0 ; i < N; i++){
         
            if(LIS[i] > 1 && LDS[i] > 1){
            int SqLen = LIS[i] + LDS[i] - 1;
            
            int removals = N - SqLen;
            
            mnRemovals = min(mnRemovals , removals);
            }
        }   
        
        return mnRemovals;  
     
    }
};