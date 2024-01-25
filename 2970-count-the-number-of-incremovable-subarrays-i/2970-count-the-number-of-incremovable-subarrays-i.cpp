class Solution {
public:
    bool is_inc(int l , int h , int n,vector<int>& nums){
        
        for(int i=1 ; i <= l ; i++){
            if(nums[i]<=nums[i-1])
                return false;
        }
        
        for(int i=h+1 ; i<n ; i++){
            if(nums[i]<=nums[i-1])
                return false;
        }
        
        if(l>= 0 && h<n && nums[l]>=nums[h])
            return false;
        
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        
        int n = nums.size(); 
        int ans = 0;
        
        for(int i=0 ; i<n ; i++){
            for(int j = i ; j< n ; j++){
                
                if(is_inc(i-1,j+1,n,nums))
                    ans++;
            }
        }
        
        return ans;
    }
};