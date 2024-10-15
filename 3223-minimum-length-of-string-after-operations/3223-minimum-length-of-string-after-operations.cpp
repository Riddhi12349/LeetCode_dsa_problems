class Solution {
public:
    int minimumLength(string s) {
        
       unordered_map <char,int> mp;
        
        for(auto ch : s){
            mp[ch]++;
        }

        int len = 0;
        
        for(auto x: mp){
            if(x.second % 2 != 0){ len += 1; }
            else{ len += 2; }
        }
        
        return len;
    }
};