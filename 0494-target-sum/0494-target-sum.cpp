class Solution {
public:
    int find(int i , int sum , vector<int>& nums, int target){
        
        int n = nums.size();
        
        if(i == n){
            if(sum == target) return 1;
            return 0;
        }
        
        int op1 = 0, op2 = 0;
        
        
        op1 = find(i+1 , sum + nums[i] , nums, target); //add +
        
        op2 = find(i+1 , sum - nums[i] , nums, target); //add -
            
        return op1 + op2;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return find(0,0,nums,target);
    }
};