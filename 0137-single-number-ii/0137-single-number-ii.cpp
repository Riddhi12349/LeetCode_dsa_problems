class Solution {
public:
    int singleNumber(vector<int>& nums) {
       
    //    [0 , 0 , 0 , 1 , 1 , 1  , 99]
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        sort(nums.begin() , nums.end());

        for(int i = 0 ; i < n ; ){    
             int p = nums[i];
             int cnt = 0;
          for(int j = i+1 ; j < i+3 && j < n; j++){
              if(nums[j] != p){
                  return p;
              }
          }
          i = i+3;
    }
    if(nums[n-1] != nums[n-2]){
        return nums[n-1];
    }
    return -1;
    }
};