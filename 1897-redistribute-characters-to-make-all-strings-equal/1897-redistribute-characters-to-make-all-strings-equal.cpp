class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        unordered_map <char,int> mp;
        
        for(int i = 0 ; i < words.size() ; i++){
             for(int j = 0 ; j  < words[i].size() ; j++){
                 mp[words[i][j]]++;
             }
        }
       
        int  n = words.size();
        
        for(auto x : mp){
            if(x.second % n != 0) return false;
        }
        
        return true;
    
    }
};
/*
q=[aabbc,bcbc,acbcb]
a=[abbc,abcbc,acbcb]
*/