class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n = chars.size() ;
        int len = 0;
        
        vector<char> ans;
        
        for(int i = 0 ; i < n ; ){
            
            char ch = chars[i]; 
            
            int j = i+1;
            ans.push_back(ch);
            
            int cnt = 1;
            len++;
            
            for(; j < n ; j++){
                if(chars[j] == ch){cnt++; }
                else{ break; }
            }
            
            i = j;
            
            if(cnt > 1){
                len++;
                
               string s  = to_string(cnt);
                
               for(int k = 0 ; k < s.size() ; k++){
                   char ch = s[k];
                   ans.push_back(ch);
                   cout << ch << endl;
               }
                
            //    cout << s << endl;
            }
            
           // cout << ch << " " << cnt << endl;
        }
        
        
        chars = ans;
        
        return ans.size();
        
    }
};