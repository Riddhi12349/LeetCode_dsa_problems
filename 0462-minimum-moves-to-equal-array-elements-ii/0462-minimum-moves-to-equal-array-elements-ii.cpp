class Solution {
public:
    int minMoves2(vector<int>& nums) {
       
     // we will find median of the array
     // min(m) - no of moves will be about the median of the array.
      
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
        int med = (n % 2 != 0) ? nums[n/2] : ((nums[n/2]+nums[(n/2)-1])/2);
        
        int ans = 0;
        
        for(int i = 0; i < n ; i++){
            ans += abs(med - nums[i]);
        }
        
        return ans;
    }
};