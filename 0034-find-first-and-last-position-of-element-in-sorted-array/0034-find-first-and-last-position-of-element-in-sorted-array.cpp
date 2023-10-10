class Solution {
public:
 // [2,2]
    int first_occurence(vector<int>& nums , int target){
        
        int low = 0 , high = nums.size()-1;

        while(low < high){
            
            int mid = (low + high)/2;
            if(nums[mid] > target){
                high = mid-1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else if(nums[mid] == target){
                high = mid;
            }
        }
     
        return low;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();

        if(!binary_search(nums.begin(),nums.end(),target)){
            return {-1,-1};
        }
        else{
     //  int pos1 = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
     //  int pos2 = lower_bound(nums.begin(),nums.end(),target+1)-nums.begin();
    
     int pos1 = first_occurence(nums , target);
     int pos2;
     if(target == nums[n-1]){
         pos2 = n;
     }
     else{
         pos2 = first_occurence(nums , target+1);
     }
        return {pos1 , pos2-1};
       
     }

    }
};