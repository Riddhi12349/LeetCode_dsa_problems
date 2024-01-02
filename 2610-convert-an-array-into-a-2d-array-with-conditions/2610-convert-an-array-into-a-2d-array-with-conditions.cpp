class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
       int n = nums.size();
       unordered_map<int,int> fmp;
       for(auto i : nums) fmp[i]++;
       
       int mxfreq = 0;
       for(auto x : fmp){
           if(x.second > mxfreq) mxfreq= x.second;
       }

       vector<vector<int>> ans(mxfreq);
       int p = 0; int cnt = n;

        while(cnt > 0){
           unordered_map <int,int> mp;

           for(int i = 0 ;  i < nums.size() ; i++){
            
             if(nums[i] != INT_MAX && mp.count(nums[i]) == 0){
                ans[p].push_back(nums[i]); 
                mp[nums[i]]++;
                nums[i] = INT_MAX; cnt--;
            }
          }
          p++;
        }

        return ans;
    }
};