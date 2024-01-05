class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size(); vector<int> v1(n,1);
        
        for(int i = 1 ; i < n ; i++){
            
            int len = 1;
            
            for(int j = i-1 ; j >= 0 ; j--){
                if(nums[i] > nums[j]) {
                    len = max(len,v1[j]+1);
                }
            }
            
            v1[i] = len;
        }
        
        int mx = *max_element(v1.begin() , v1.end());
        
        return mx;
    }
};