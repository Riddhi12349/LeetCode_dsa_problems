class Solution {
public:
    vector<vector<int>> ans;
    
    void find(int i, vector<int>& a , vector<int>& v1){
        
        if(i >= a.size()) {
            ans.push_back(v1);
            return;
        }
        
        //pick
        v1.push_back(a[i]);
        find(i+1 , a, v1);
        v1.pop_back();
        
        //not-pick
        int j=i+1;
        for(; j < a.size() ; j++){
            if(a[j] == a[i]) continue;
            else break;
        }
        find(j , a, v1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
       
        sort(a.begin() , a.end());
        
        vector<int> v1;
        find(0 , a , v1);
        return ans;
    }
};