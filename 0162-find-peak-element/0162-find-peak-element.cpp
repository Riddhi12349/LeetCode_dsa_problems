class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        if(n == 2){
            int x =  max(nums[0] ,nums[1]);
            int t;
            (x == nums[0]) ? t = 0 : t = 1;
            return t;
        }

        if(nums[0] > nums[1]){ return 0; }

        if(nums[n-1] > nums[n-2]){ return n-1; }
        
        int h = n-2 , l = 1;
        while(l <= h){
            int mid = (l + h)/2;

            if(nums[mid] < nums[mid + 1]){
                l = mid + 1;
            }
            else if(nums[mid] < nums[mid-1]){
                h = mid - 1;
            }
            else{
             //   return nums[mid];
             return mid;
            }
        }
        return -1;
    }
};