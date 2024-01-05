class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> lis(n,1);
        
        for(int i = 1 ; i < n ; i++){
            
            int len = 1;
            
            for(int j = i-1 ; j >= 0 ; j--){
                if(nums[i]>=nums[j]){
                    len = max(len , 1+lis[j]);
                }
            }
            
            lis[i] = len;
        }
        
        int mx = *max_element(lis.begin() , lis.end());
        return n-mx;
    }
};