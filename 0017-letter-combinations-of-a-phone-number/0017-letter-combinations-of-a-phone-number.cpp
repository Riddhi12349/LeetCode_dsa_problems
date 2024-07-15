class Solution {
public:
    unordered_map <char,vector<string>> mp;
    
    void create(){
      
       mp['2'] = {"a" , "b", "c"};
       mp['3'] = {"d" , "e", "f"};
       mp['4'] = {"g" , "h" , "i"};
       mp['5'] = {"j" , "k" , "l"};
       mp['6'] = {"m" , "n" , "o"};
       mp['7'] = {"p" , "q" , "r" , "s"};
       mp['8'] = {"t" , "u" , "v"};
       mp['9'] = {"w" , "x" , "y", "z"};
        
    }
    
    vector<string> find(int i , string digits){
        
        int n =  digits.size(); 
        
        vector<string> cur;
        
        if(i >= n){
            cur.push_back("");
            return cur;
        }
        
        vector<string> nxt = find(i+1 , digits);
        
        char ch = digits[i];
        vector<string> v1 = mp[ch];
            
        for(int i = 0 ; i < v1.size() ; i++){
            for(int j = 0 ; j < nxt.size() ; j++){
                string tmp = v1[i] + nxt[j];
                cur.push_back(tmp);
            }
        }
        
        return cur;
    }
    
    vector<string> letterCombinations(string digits) {
        
       if(digits.size() == 0) return {};
        
       create();
       return find(0 , digits);
    }
};