class Solution {
public:
    string find(int n , int k){
        
        if(n==1) return "0";
        
        string tmp = find(n-1 , k);
        
        string tmp2 = tmp + "1";
        
        string p = "";
        for(auto ch : tmp){
            if(ch == '0') p += '1';
            else p += '0';
         }
        
        reverse(p.begin() , p.end());
        
        tmp2 += p;
        
        return tmp2;
    }
    
    char findKthBit(int n, int k) {
        
       string s =  find(n , k);
        
       return s[k-1];
    }
};