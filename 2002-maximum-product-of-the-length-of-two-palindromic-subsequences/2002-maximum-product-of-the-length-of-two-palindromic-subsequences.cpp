class Solution {
public:
    int ans;
    bool ispal(string t){
       
        int n = t.size() , j=n-1; 
        
        for(int i=0 ; i<=(n/2) && i<j ; i++,j--){
            if(t[i]!=t[j]) return false;
        }
        return true;
    }
    
    void find(int i, string s, string& s1, string& s2){
        
        if(i>=s.size()){
            if(ispal(s1) && ispal(s2)){
               int l = (s1.size()*s2.size());
                ans = max(ans,l);
             }
            return;
        }
        
        /*
        int op1 = find(i+1 , s , s1+s[i] , s2);
        int op2 = find(i+1 , s, s1, s2+s[i]);
        int op3 = find(i+1 , s , s1, s2);
        */

//ABOVE method will  result TLE , SINCE , new copy is made each time.so,avoid this we will use backtracking.
       
        
       // return max({op1,op2,op3});
       
        find(i+1,s,s1,s2);
        
        s1.push_back(s[i]);
        find(i+1, s, s1, s2);
        s1.pop_back();
        
        s2.push_back(s[i]);
        find(i+1, s , s1, s2);
        s2.pop_back();
    }
    
    int maxProduct(string s) { 
        ans=0;
        string s1="",s2="";
        find(0, s ,s1 , s2);
        return ans;
    }
};