class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
       
        unordered_map <int,int> mp;
        for(auto x : arr) mp[x]++;
        
        int p = arr.size()*0.25;
        
        int ans = -1;
        for(auto x : mp){
            if(x.second > p)return x.first;
        }
        return ans;
    }
};