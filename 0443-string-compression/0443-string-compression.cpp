class Solution {
public:
    int compress(vector<char>& chars) {

      string ans = "";
      int n = chars.size();
      for(int i = 0 ; i < n ; ){
          int j = i+1;
          int cnt = 1;
          char temp = chars[i];
          ans.push_back(temp);
          while(j < n){
              if(chars[j] == temp){
                  cnt++;
                  j++;
              }
              else{ break; }
          }

          if(cnt != 1){
              
              string str = to_string(cnt);
              for(int i = 0 ; i < str.size() ; i++){
                ans.push_back(str[i]);
            }
          }
          i = j;
      }  
     chars.clear();
     for(int i = 0 ; i < ans.size() ;i++){
         chars.push_back(ans[i]);
     }
    
      return ans.size();
    }
};