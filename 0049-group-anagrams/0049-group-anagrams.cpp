class Solution {
public:
    /*
    bool isanag(string a,string b){
        if(a.size()==b.size()){
            unordered_map <char,int> mp1,mp2;
            for(int i=0;i<a.size();i++){
                mp1[a[i]]++;
                mp2[b[i]]++;
            }
            for(auto x : b){
                if(mp2[x]!=mp1[x]) return false;
            }
            return true;
        }
        return false;
    }
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();
        unordered_map <string,vector<string>> mp;
        
        for(int i=0 ; i<n ; i++){
            string word = strs[i];
            sort(word.begin() , word.end());
            mp[word].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        
       /* for(int i= 0 ; i < n ; i++){
        
            string t = strs[i]; int f1=0;
           
            for(int j = 0 ; j < v1.size() ; j++){
                string f  = v1[j][0];
                if(isanag(f,t)){
                    v1[j].push_back(t);
                    f1=1;
                    break;}     
            }
            if(f1==0){ v1.push_back({t});}
        }*/
        
        for(auto x : mp)
            ans.push_back(x.second);
        
        return ans;
    }
};