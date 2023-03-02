class Solution {
public:
     
     void merge(vector<int>& nums , int l , int mid , int h){

         int i = l;
         int j = mid + 1;
         int k = l;
         int b[100000];
       
         while(i <= mid && j <= h){
             if(nums[i] <= nums[j]){
                 b[k] = nums[i];
                 i++;
             }
             else{
                 b[k] = nums[j];
                 j++;
             }
             k++;
         }

         while(i <= mid){
             b[k] = nums[i];
             i++;
             k++;
         }

         while(j <= h){
             b[k] = nums[j];
             j++;
             k++;
         }

         for(int t = l ; t <= h ; t++){
             nums[t] = b[t];
         }
     }
     void mergeSort(vector<int>& nums , int l , int h){
      int mid;
         if(l < h){
            mid = (l + h)/2;
            mergeSort(nums , l , mid);
            mergeSort(nums , mid + 1 , h);
            merge(nums , l , mid , h);
         }
     }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums , 0 , nums.size() - 1);
        return nums;
    }
};