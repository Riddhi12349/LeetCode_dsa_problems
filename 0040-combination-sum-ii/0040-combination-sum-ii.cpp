class Solution {
public:
    vector<vector<int>> ans;
    
    void find(int i , vector<int>& a , int t , vector<int>& v1){
        
        if(t < 0) return;
        
        if(t == 0){ 
            ans.push_back(v1); return;
        }
        
        if(i >= a.size()){
          return;  
        }
        
        v1.push_back(a[i]); 
        
        int j=i+1;
        for(j =i+1 ; j < a.size() ; ){
            if(a[j] == a[i]) { j++; }
            else { break; }
        }
        find(i+1 , a , t-a[i] , v1);
        v1.pop_back();
        
        find(j , a , t, v1);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& a, int t) {
        
        sort(a.begin() , a.end());
        
        vector<int> v1;
        find(0 , a, t , v1);
        
        return ans;
        
    }
};