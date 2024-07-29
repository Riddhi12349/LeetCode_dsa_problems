class Solution {
public:
    string minWindow(string s, string t) {
        
        int i = 0 , j = 0  , cnt = 0 , n = s.size();
        
        unordered_map <char,int> mp , mp_t;
        
        for(auto ch : t){
            mp_t[ch]++;
        }
        
        int ans = INT_MAX; string ans_str = "";
        
        while(j < n){
            
            mp[s[j]]++;
            
            if(mp_t.count(s[j]) > 0){
                if(mp[s[j]] <= mp_t[s[j]]){
                    cnt++;
                }
            }
            
            if(cnt == t.size()){
                
                while(i <= j){
                    if(mp_t.count(s[i]) == 0 ||   mp[s[i]] > mp_t[s[i]] ){
                        if(--mp[s[i]] == 0){
                            mp.erase(s[i]); 
                        }
                        i++;
                    }
                    else{
                        break;
                    }
                }
                
                if(ans > j-i+1){
                    ans = j-i+1;
                    ans_str = s.substr(i , j-i+1);
                }
            }
            
            j++;
        }
        
        
      return ans_str;
    }
};