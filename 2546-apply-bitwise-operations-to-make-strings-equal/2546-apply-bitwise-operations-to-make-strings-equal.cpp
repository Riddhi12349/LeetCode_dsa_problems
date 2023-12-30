class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        
        if(s.size() != t.size()) return false;
        
        int zt = 0 , ot = 0 , zn = 0 , on = 0;
        
        for(int i = 0 ; i  < s.size() ; i++){
            if(s[i]=='1') on++;
            else if(s[i]=='0') zn++;
            
            if(t[i] == '1') ot++;
            else if(t[i] == '0') zt++;
        }
       
        if((ot == 0 && zn == 0) || (on == 0 && zt == 0) 
          || (ot != 0 && on == 0) || 
           (ot == 0 && on > 0))
            return false;
        
        
        return true;
    }
};