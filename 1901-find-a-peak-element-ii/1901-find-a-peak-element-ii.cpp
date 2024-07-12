class Solution {
public:
    int find(vector<vector<int>>& mat , int mid){
        
        int no = 0 , mxrowIndx = -1 , mxrowEl = -1;
        
        for(int i=0 ; i < mat.size() ; i++){
           
            if(mat[i][mid] > mxrowEl){
                mxrowEl = mat[i][mid];
                mxrowIndx = i;
            }
        }
        
        return mxrowIndx;
    }
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int m = mat.size() , n = mat[0].size();
        
        // binary search on cols
        int low = 0  , high = n-1;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            
            int mxRowIndx = find(mat , mid);
            
            int p = mat[mxRowIndx][mid] ;
            
            int r = mxRowIndx , c = mid;
            
            if((c-1 < 0 || mat[r][c] > mat[r][c-1]) && 
               (c+1 >= n || mat[r][c] > mat[r][c+1]) ){
                
                return {r , c};
            }
           
            else if((c-1 >= 0) && mat[r][c-1] > p){
                high = mid-1;
            }
            
            else{
                low = mid+1;
            }
        }
        
        return {-1, -1};
    }
};