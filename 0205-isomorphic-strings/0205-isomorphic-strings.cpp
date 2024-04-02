class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = s.size();
        unordered_map <char,char> mp;
        
        for(int i = 0 ; i < n ; i++){
            if(mp.count(s[i]) == 0){
                  mp[s[i]] = t[i];
            }
            else{
                if(mp[s[i]] != t[i]) 
                    return false;
            }
        }
        
        mp.clear();
        
        for(int i = 0 ; i < n ; i++){
            if(mp.count(t[i]) == 0){
                mp[t[i]] = s[i];
            }
            else{
                if(mp[t[i]]!= s[i])
                    return false;
            }
        }
        
        return true;
    }
};