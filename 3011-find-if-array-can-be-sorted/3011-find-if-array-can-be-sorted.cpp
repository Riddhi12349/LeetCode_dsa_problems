class Solution {
public:
    bool isSameSetBits(int x , int y){
        
        int cnt1 = 0 , cnt2 = 0;
        
        while(x > 0){
            
            cnt1 += (x % 2);
            x = x/2;
        }
        
        while(y > 0){
            
            cnt2 += (y % 2);
            y = y/2;
        }
        
        return cnt1 == cnt2;
    }
    
    bool canSortArray(vector<int>& nums) {
       
     //   16,8,4,2,1
            
        int n = nums.size();
        
        for(int i = 0; i < n ; i++){
            
            for(int j = i ; j >= 0 ; j--){
                
                if(j-1 >= 0 && nums[j] < nums[j-1]){
                    
                    if(isSameSetBits(nums[j] , nums[j-1])){
                        swap(nums[j] , nums[j-1]);
                    }
                }
            }
        }
        
        for(int i = 0 ; i < n-1 ; i++){
            if(nums[i] > nums[i+1]) return false;
        }
        
        return true;
            
         
    }
};