class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     //= 1*3*4*2*2
     //   [1,2,3,9,5,6,7,8,9,]
        int n = nums.size();
        
        for(int i = 0 ; i < n  ; i++){
          while(nums[i] != i+1 && nums[nums[i]-1] != nums[i]){
              swap(nums[i] , nums[nums[i]-1]);}
        }
         
        for(auto x : nums) cout << x << " ";
        
        cout << endl;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != i+1) return nums[i];
        }
         
        return -1;
    }
};