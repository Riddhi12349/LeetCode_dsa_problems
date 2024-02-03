class Solution {
public:
    vector<vector<int>> ans;
   
    void find(int i, int sum, int t, vector<int>& cd,vector<int>& v1){
        
        int n = cd.size();
        
        if(sum==t) {ans.push_back(v1); return; }
        if(sum > t) return; //controlled_recursion step
        if(i>=n) return;
        
        v1.push_back(cd[i]);
        find(i+1,sum+cd[i],t,cd,v1);
        v1.pop_back();
        //avoid all occ of that element
        int j=i+1;
        for(;j<n;j++){
            if(cd[j]!=cd[i])break;
        }
        find(j,sum,t,cd,v1);        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& cd, int target) {
        
        sort(cd.begin(),cd.end());
        
        vector<int> v1;
        find(0,0,target,cd,v1);
        return ans;
    }
};