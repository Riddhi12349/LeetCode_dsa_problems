class Solution {
public:

        int arraySign(vector<int>& nums) {
        
        long cnt1 = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i] == 0){ return 0; }
         if(nums[i] < 0){ cnt1++; }
        }
        if(cnt1 % 2 == 0){ return 1; }
        else{ return -1; }
    
    }
};