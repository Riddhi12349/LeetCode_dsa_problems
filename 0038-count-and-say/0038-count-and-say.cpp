class Solution {
public:
    
    string RLE(int n){
        
        if(n == 1) { return "1"; }
        
        string prv = RLE(n-1);
        
        string res = "";
     
        for(int i = 0 ; i < prv.size() ; i++){
            
            int cnt = 1; // cnt of ith char
            //now , counting for chars from i+1 , same to that of ith
            while(i < prv.size()-1 && prv[i] == prv[i+1]){
                cnt++; i++;
            }
            
            res += to_string(cnt) + string(1 , prv[i]);
            
        }
        
        return res;
  
    }
    string countAndSay(int n) {
        
       return RLE(n);
    }
};