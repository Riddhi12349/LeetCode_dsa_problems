class Solution {
public:
    unordered_map <char,string> mp;
    vector<string> ans;
    void generate(){
     
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
    }
    
    void find(string digits , int pos , vector<string> v1){
         
        if(pos >= digits.size()) {
            ans =v1;
            return;}
        
        
        string tmp = mp[digits[pos]];//ghi
        vector<string> v2;
        
        for(int i = 0 ; i < tmp.size() ; i++){
            
            for(int j = 0 ; j < v1.size() ; j++){
                string p = v1[j];
                p += tmp[i];
                v2.push_back(p);
            }
        
        
             if(v1.size() == 0){
               string x = "";
                 x += tmp[i];
               v2.push_back(x);         
             }
            
     } 
        find(digits , pos+1 , v2);
    }
    
    vector<string> letterCombinations(string digits) {
        
        generate();
        
        vector<string> v1;
        find(digits , 0 , v1);
        
        return ans;
    }
};