class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int m = mat.size() , n = mat[0].size();
        
        int row = -1;
        
        int low= 0, high = m-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(mat[mid][0] > target){
                high = mid-1;
            }
            else{
                row = mid;
                low = mid+1;
            }
        }
        
        if(row == -1) return false;
        
        int col = -1;
        
         low= 0, high = n-1;
         while(low <= high){
             
             int mid = (low + high)/2;
             if(mat[row][mid] > target){
                 high = mid-1;
             }
             else{
                 col = mid;
                 low = mid+1;                 
             }
         }
        
        if(col == -1 || col >= n) return false;
        
        if(mat[row][col] == target) return true;
        return false;
     }
};