class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long subarray = 0;
        long long ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                subarray += 1;
                ans += subarray;
            }
            else
           {
               subarray = 0;
           }
        }
        return ans;
    }
};