class Solution {
public:
    vector<vector<int>> ans;
  
    void find(int indx,vector<int>& a){
        
        int n = a.size();
        
        if(indx >= n){
            ans.push_back(a);
            return;
        }
        
        unordered_map <int,int> mp;
        
        for(int i=indx ; i<n ; i++){
            
           if((i==indx )|| (i>indx && mp.count(a[i])==0)){  
               mp[a[i]]++;
               swap(a[indx],a[i]);
               find(indx+1,a);
               swap(a[indx],a[i]);    
           }   
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        find(0,nums);
        
        return ans;
    }
};