class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long subarray_size = 0;
        long long ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                subarray_size += 1;
                ans += subarray_size;
            }
            else
           {
               subarray_size = 0;
           }
        }
        return ans;
    }
};