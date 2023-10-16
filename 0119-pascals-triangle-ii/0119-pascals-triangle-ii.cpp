class Solution {
public:
    vector<int> getRow(int rowIndx) {
        
      vector<int> pt[rowIndx+1];
     
       for(int i = 0 ; i <= rowIndx ; i++){
           vector<int> v1(i+1, 1);
           pt[i] = v1;
       }
        
        for(int i= 2  ; i <= rowIndx ; i++){
            for(int j = 1 ; j <= i-1 ; j++){
                pt[i][j] = pt[i-1][j-1] + pt[i-1][j]; 
            }
        }
        
        return pt[rowIndx];
    }
};

 