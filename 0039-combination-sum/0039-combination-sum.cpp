class Solution {
public:
    vector<vector<int>> ans;
    
    void find(int i , vector<int>& a , int t , vector<int>& v1){
        
        if(t < 0) return;
        if(t == 0) { 
           ans.push_back(v1);
           return;
        }
        if(i >= a.size()){
            return;
        }
        
        v1.push_back(a[i]);
        find(i , a, t-a[i] , v1);
        v1.pop_back();
        find(i+1 , a , t, v1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        
        vector<int> v1;
        find(0 , a , t , v1);
        
        return ans;
    }
};