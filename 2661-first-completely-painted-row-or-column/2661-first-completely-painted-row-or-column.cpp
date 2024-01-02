class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        unordered_map <int,int> mp;
        
        for(int i = 0 ; i < arr.size() ; i++){
            mp[arr[i]] = i;
        }
        
        int m = mat.size() , n = mat[0].size();
       
         int mn_i_row = INT_MAX;
        
        for(int i = 0 ; i < m ; i++){
            
            int indx = -1;
            
            for(int j = 0 ; j < n ; j++)
                indx = max(indx , mp[mat[i][j]]);
            
            mn_i_row = min(mn_i_row , indx);
        }
        
        int mn_i_col = INT_MAX;
            
        for(int j = 0 ; j < n ; j++){
            
            int indx = -1;
            
            for(int i = 0 ; i < m ; i++)
                indx = max(indx , mp[mat[i][j]]);
            
            mn_i_col = min(mn_i_col , indx);
        }
        
        return min(mn_i_row , mn_i_col);
    }
};