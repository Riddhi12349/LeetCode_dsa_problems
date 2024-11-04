class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.size() != goal.size()) return false;
        
        for(int i = 0 ; i < s.size() ; i++){
        
           string tmp = s.substr(i);
           
           int n1 = tmp.size();
            
           string tmp2 = goal.substr(0 , n1);
            
            if(tmp == tmp2){
                
                string end = goal.substr(n1);
                
                int n2 = end.size();
                string st = s.substr(0 , n2);
                
                if(end == st) return true;
                    
            }
                
        }
        
        return false;
    }
};