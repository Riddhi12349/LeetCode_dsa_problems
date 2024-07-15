class Solution {
public:
    vector<vector<int>> ans;
    int K , N;
    
    void find(int i , int cnt , int s,  vector<int>& v1){
        
        if(cnt == K || i >= 10 || s > N){
            if(s == N && cnt == K){
                ans.push_back(v1);
                return;
            }
            
            return;
        }
        
        //pick
        v1.push_back(i);
        find(i+1 , cnt+1 , s + i , v1);
        v1.pop_back();
        
        //not-pick
        find(i+1 , cnt, s , v1);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
       K= k  , N=n;
        
        vector<int> v1;
        find(1 , 0 , 0, v1);
            
        return ans;  
    }
};