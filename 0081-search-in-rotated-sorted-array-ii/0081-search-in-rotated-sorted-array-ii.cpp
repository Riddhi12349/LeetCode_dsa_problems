class Solution {
public:
//Will not work for if we have:
//[1,2,1,1,1,1]
//if a[mid]==a[low]==a[high] you cannot find the right position of the pivot
// so it is impt to remove duplicate elements from endpoints
// so that if a[low]==a[high]==X but X!=a[mid]  , for eg:[1,2,1] , then only you can compare that middle element with extreme element i.e. a[r]
  
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int low = 0 , high = n-1;
        
        while(low < high){
            
            while(low < high && nums[low] == nums[low + 1])
                low++;
            
            while(low < high && nums[high] == nums[high - 1])
                high--;

            int mid = (low + high)/2;

            if(nums[mid] > nums[high]){
                low = mid + 1;
            }
            else{
                high = mid;
                // if(nums[mid] <= nums[pvt_indx])
                // pvt_indx = mid;
            }
        }
        
        int pvt_indx = high;
        
  
    if(binary_search(nums.begin() + pvt_indx , nums.end() , target)) 
        return true;
   
   if(binary_search(nums.begin() , nums.begin()+pvt_indx , target))
       return true;
   
       return false;
        
    }
};
