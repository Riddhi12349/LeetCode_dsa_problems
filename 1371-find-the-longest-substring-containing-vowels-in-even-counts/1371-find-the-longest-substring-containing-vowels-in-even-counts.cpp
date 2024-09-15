class Solution {
public:
    int findTheLongestSubstring(string s) {
        
        unordered_map <char,int> mp = {{'a' , 1} , {'e' , 2} , {'i' , 4} ,
                                       {'o' , 8} , {'u' , 16}};
      
        int seen[32];
        memset(seen , -1 , sizeof(seen));
        
        int mask = 0 , mxlen = 0;
        
        for(int i = 0 ; i < s.size() ; i++){
            
           mask = mask^mp[s[i]];
       //    cout << mask << " ";
            
           if(mask != 0 && seen[mask]==-1){
                seen[mask]=i;
           }
         
           mxlen = max(mxlen , i-seen[mask]);
        }
     //   cout << endl;
        
        return mxlen;
    }
};