class Solution {
public:
/*
   int f(vector<int>& nums , int l , int h){ 
       int mid , n = nums.size() ,ans1 = -1 , ans2 = -1;
       if(l <= h){
           mid = (l + h)/2;
    if(mid != n-1 && nums[mid] == nums[mid + 1]){
        ans1 = f(nums , l , mid - 1);
        ans2 = f(nums , mid + 2 , h);
    }
    else if(mid != 0 && nums[mid] == nums[mid - 1]){
        ans1 = f(nums , l , mid - 2);
        ans2 = f(nums , mid + 1 , h);
    }
    else{
        return nums[mid];
    }
    if(ans1 != -1 && ans2 == -1){ return ans1;   }
    else{ return ans2; }
  }
       return -1;
   }
    int singleNonDuplicate(vector<int>& nums) {
        return f(nums , 0 , nums.size() - 1);
    }*/

    int singleNonDuplicate(vector<int>& nums){
 
 // edge cases
 int n  = nums.size();
  if(nums.size() == 1){ return nums[0]; }
  if(nums[0] != nums[1]){ return nums[0]; }
  if(nums[n-1] != nums[n-2]){ return nums[n-1];  }



        int lo = 0 , h = nums.size()-1 , mid;
        while(lo <= h){
            mid = (lo + h)/2;
            if(nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]){
                return nums[mid];
            }
        else if(nums[mid] == nums[mid - 1]){
                int leftCnt = mid - 1 - lo;
                if(leftCnt % 2 == 0){ lo = mid + 1; }
                else { h = mid - 2;}
        }
        else if(nums[mid] == nums[mid + 1]){
            int rightCnt = h - mid-1;
            if(rightCnt % 2 == 0){ h = mid - 1;    }
            else { lo = mid + 2;}
        }
        }
        return -1;
    }
};