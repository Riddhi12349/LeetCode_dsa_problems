class Solution {
public:
    int bsearch(vector<vector<int>>& matrix, int target) {
      
       int m = matrix.size();
       int low = 0 , high = m-1 , ans = -1;
      
       while(low <= high){
           
           int mid = (low + high)/2;

           if(matrix[mid][0] == target){
               return mid;
           }
           else if(matrix[mid][0] > target){
               high = mid-1;
           }
           else{
               ans = mid;
               low = mid+1;
           }
       }

       return ans;
    
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

 int m = matrix.size() , n = matrix[0].size();
  // finding row of the target element
  
  int pos1 = bsearch(matrix , target);
  
 if(pos1 != -1 && binary_search(matrix[pos1].begin() , matrix[pos1].end() , target)){
     return true;
 }
 return false;
    }
};