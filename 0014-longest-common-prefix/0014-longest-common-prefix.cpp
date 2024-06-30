class Solution {
public:
    string find(string x , string y){
       
        string tmp = "";
        for(int i = 0 , j = 0 ; i < x.size() && j < y.size() ; i++ , j++){
            if(x[i]==y[j])  tmp += x[i];
            else break;
        }
        
        return tmp;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        
        string st = strs[0];
        for(int i = 1; i < strs.size() ; i++){
            string common_pref = find(st , strs[i]);
            st = common_pref;
        }
        
        return st;
    }
};