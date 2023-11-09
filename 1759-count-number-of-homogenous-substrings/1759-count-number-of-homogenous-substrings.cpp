class Solution {
public:
    const int mod = 1e9+7;
    int countHomogenous(string s) {
     
        vector<int> pref(s.size() , 1);
        
        for(int i = 1 ; i < s.size() ; i++){
                if(s[i] == s[i-1])
                    pref[i] = pref[i-1]+1;
        }
        
        long long ans= 0;
        for(int i = 0 ; i < s.size(); i++){
            ans += pref[i];
            ans = ans % mod;
        }
        
        return ans;
    }
};