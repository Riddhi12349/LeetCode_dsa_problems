class Solution {
public:
    bool isgood(vector<int>& nums){
        
        int n = nums.size();
        for(int i=0 ; i<n-1 ; i++){
            if(nums[i]==nums[i+1])
                return false;
        }
        return true;
    }
    
    void wiggleSort(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> v1(nums.begin() , nums.end());
        
        sort(v1.begin() , v1.end());
      /*  
        int j=0;
        for(int i=0 ; i<nums.size() ; i+=2,j++){
            nums[i] = v1[j];
        }
        for(int i=1 ; i<nums.size() ; i+=2,j++){
            nums[i] = v1[j];
        }
        
       if(!isgood(nums)){
      */     //put in decr-order
           int j = n-1;
           for(int i=1 ; i<n ; i+=2,j--){
               nums[i] = v1[j];
           }
           for(int i=0 ; i< n ; i+=2,j--){
               nums[i] = v1[j];
           }
      // }
        
    }
};
/*
[1,2 ,1,3 , 2,3]
==>1,1,1,4,5,6
[1,4,1,5,1,6]
*/