class Solution {
public:
      // abadbbabbccab
    int lengthOfLongestSubstring(string s) {
        
       unordered_map <char,int> mp;
       
       int len = 0 , mxlen = 0 , j = 0;
       
       for(int i = 0 ; i < s.size() ; i++){
           
           if(mp.count(s[i]) == 0){
               mp[s[i]]++;      
           }
           else{
          //     mp.clear(); WRONG
               while(j<i && mp[s[i]] > 0){
                   if(--mp[s[j]] == 0){ mp.erase(s[j]); }
                   j++;
               }
             
               mp[s[i]]++;
           }
           
           mxlen = max(mxlen , i-j+1);
       }
        
        return mxlen;
        
    }
};