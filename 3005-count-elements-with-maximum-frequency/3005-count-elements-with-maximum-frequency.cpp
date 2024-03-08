class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        for(auto x: nums)
             mp[x]++;
        
        int mxfreq = 0;
        for(auto x : mp){
            mxfreq = max(mxfreq , x.second);
        }
        
        int tot = 0;
        for(auto x : mp){
            if(x.second==mxfreq)
                tot+= mxfreq;
        }
         
        return tot;
    }
};