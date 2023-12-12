class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int p = nums[n-1] , q = nums[n-2];
        return (p-1)*(q-1);
    }
};