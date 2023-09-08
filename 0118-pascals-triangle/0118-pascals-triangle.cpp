class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans(numRows);
     
        for(int i = 0 ; i < numRows ; i++){
            vector<int> v1(i+1 , 1);
            ans[i] = v1;
        }
        
        for(int i = 2 ; i < numRows ; i++){
            for(int j = 1; j < i ; j++){
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        
        return ans;
    }
};