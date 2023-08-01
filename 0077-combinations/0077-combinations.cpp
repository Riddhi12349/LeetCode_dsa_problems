class Solution {
public:
   vector<vector<int>> ans;
   void helper(int n , int k , int i , vector<int>& v1){

       if(k == 0){
           ans.push_back(v1);
           return;
       }
       if(i > n){
           return;
       }

       v1.push_back(i);
       helper(n , k-1 , i+1 , v1);
       v1.pop_back();
       helper(n , k , i+1 , v1);
   }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v1;
        helper(n , k , 1 , v1);
        return ans;
    }
};