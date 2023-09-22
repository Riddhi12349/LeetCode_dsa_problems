class Solution {
public:
    
    bool find(int i, int j , string s , string t){
        
        if(i >= s.size()) return true;
        
        if(j >= t.size()) return false;
        
        bool ans = false;
        
        if(s[i] == t[j]){
          ans = ans |  find(i+1 , j+1, s , t);
        }
        else{
          ans = ans |  find(i , j+1 , s, t);
        }
        
        return ans;
    }
    bool isSubsequence(string s, string t) {
        
      return  find(0 , 0 , s, t);
    
    }
};