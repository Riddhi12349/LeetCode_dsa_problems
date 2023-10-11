class Solution {
public:
       
    int nCr(int n){
        
        int ans = (n*(n-1))/2;
        return ans;
    }
    
    int numIdenticalPairs(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
   
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }
        
        int ans = 0;
        for(auto x : mp){
            if(x.second == 2){
                ans += 1;
            }
            else if(x.second > 2){
                ans += nCr(x.second);
            }
        }
        
        return ans;
    }
};