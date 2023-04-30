class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        
        unordered_map<int,int> act_indx_map;
        for(int i = 0 ; i < nums.size() ; i++){
            act_indx_map[nums[i]] = i;
        }

        int last_indx = 0;
        sort(nums.begin() , nums.end());
        long long ans = nums.size();
        int n = nums.size();
        for(int i = 0 ; i < nums.size() ; i++){
            if(act_indx_map[nums[i]] < last_indx){
                ans += n-i;
            }
            last_indx = act_indx_map[nums[i]];
        } 

        return ans;
    }
};