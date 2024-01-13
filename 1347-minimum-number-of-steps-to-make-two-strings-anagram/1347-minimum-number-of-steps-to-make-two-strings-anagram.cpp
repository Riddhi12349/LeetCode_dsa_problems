class Solution {
public:
    
    int minSteps(string s, string t) {
        
        unordered_map <char,int> mp_s , mp_t;
     
        for(auto ch : t) mp_t[ch]++;
        for(auto ch : s) mp_s[ch]++;
        
        int ans=0;
        
        for(auto x: mp_s){
            if(mp_t[x.first] < x.second) {
                ans+= abs(x.second-mp_t[x.first]);
            }
        }
        
        return ans;
    }
};