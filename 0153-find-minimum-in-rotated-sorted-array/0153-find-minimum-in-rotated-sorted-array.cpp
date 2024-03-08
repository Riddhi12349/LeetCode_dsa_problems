class Solution {
public:
    int findMin(vector<int>& nums) {
       // [4,5,6,7,0,1,2,3]
        
        int n = nums.size();
        int low = 0 , high = n-1;
        
        while(low < high){
            
            int mid = (low + high)/2;
            
            if(nums[mid] > nums[high]){ low = mid+1; }
            else if(nums[mid] < nums[high]) { high = mid; }
            else if(mid-1 >= 0 && nums[mid-1] >= nums[mid]){
                return nums[mid];
            }
        }
        
        return nums[low];
    }
};