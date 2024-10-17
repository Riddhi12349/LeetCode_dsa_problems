class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        
        int n = nums.size(); long long score = 0;
        
        int prv_i = 0;
        
        for(int i = 1 ; i < n ; i++){
            
            if(i==n-1 || nums[i] > nums[prv_i]){
                score += (i-prv_i)*1ll*nums[prv_i];
                prv_i = i;
            }
        }
        
        return score;
        
    }
};