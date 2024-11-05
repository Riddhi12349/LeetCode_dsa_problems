class Solution {
public: 
   // 10100111000110000=>
    int minChanges(string s) {
        
        int ops = 0;
        
        for(int i = 0 ; i < s.size()-1 ; i+=2){
            
           if((s[i] == '1' && s[i+1] == '0') || (s[i] == '0' && s[i+1] == '1')) ops++;
        }
        
        return ops;
    }
};