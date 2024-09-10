class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        //TAKE TRANSPOSE OF THE MATRIX-> ROW TO COLUMN 'AND' COLUMN TO ROW
        
        //TRANSPOSE OF MATRIX WILL HAPPEN ALONG THE DIAGONAL 
        
        //{I,J} => {J,I}
        
        for(int  i = 0 ; i < n ; i++){
            for(int j= i ; j < n ; j++){
                
                swap(mat[i][j] , mat[j][i]);
            }
        }
        
        for(int  i = 0 ; i < n ; i++){
            
            reverse(mat[i].begin() , mat[i].end());
        }
    }
};