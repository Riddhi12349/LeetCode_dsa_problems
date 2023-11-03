class Solution {
public:
  
    int minimumSeconds(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> a(nums.begin(),nums.end());
        for(int i = 0 ; i < n ; i++)
            a.push_back(nums[i]);
        
               
        unordered_map<int,vector<int> > mp;
        for(int i = 0 ; i < a.size() ; i++){
            mp[a[i]].push_back(i);
        }
        
//        print(mp);
        
        int mnTime = INT_MAX;
        
        for(auto x : mp){
            
            int mxlen = 0;
            vector<int> v = x.second;
            for(int i = 0 ; i < v.size()-1 ; i++){
                mxlen = max(mxlen , v[i+1]-v[i]-1);
            }
            mnTime = min(mnTime , (mxlen+1)/2);
        }
        
           return mnTime;    
        }
};