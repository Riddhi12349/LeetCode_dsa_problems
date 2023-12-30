class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        
        int p = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            p = p^nums[i];
        }
        
        return p;
    }
};