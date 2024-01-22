class Solution {
public:
    string getHint(string secret, string guess) {
       
        int b = 0 , c = 0;
        int n = secret.size();
        unordered_map <char,int> mp;
        
        for(int i=0 ; i<n ; i++){
            if(secret[i]==guess[i]){
                b++;}
            else{
                mp[secret[i]]++;}
        }
        
        for(int i = 0 ; i < n ;i++){
            if(guess[i] != secret[i]  && mp[guess[i]]>0){
                   c++;
                mp[guess[i]]--;
            }
        }
        
        string t = to_string(b)+"A"+to_string(c)+"B";
        return t;
    }
};