class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        
        unordered_map<int,int> mp;
        for(auto x : nums1) mp[x]++;
        
        for(auto x : nums2){
            if(mp.count(x) > 0){
                ans.push_back(x);
                mp.erase(x);
            }
        }
        
        return ans;
    }
};