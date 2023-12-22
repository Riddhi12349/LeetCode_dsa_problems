class Solution {
public:
    int maxScore(string s) {
        
        int mxscore = 0;
        
        for(int i = 0 ; i < s.size()-1 ; i++){
          
           string lft = s.substr(0,i+1);
           string rt =  s.substr(i+1);
           
           int z = 0;
           for(int i = 0 ; i < lft.size() ; i++){
               if(lft[i] == '0') z++;
           }
           
           int o = 0;
           for(int i = 0; i < rt.size() ; i++){
               if(rt[i] == '1') o++;
           }
            
           mxscore = max(mxscore , z+o);
        }
        
        return mxscore;
    }
};