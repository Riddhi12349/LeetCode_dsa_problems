class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
      
        int n = s.size();
        vector<string> ans;
        
        if(n<10) return ans;
        
        unordered_map <string,int> mp;
        
        for(int i=0; i<=n-10; i++){   
            string t = s.substr(i,10);
         //   cout << t << endl;
            mp[t]++;
        }
        
        for(auto x: mp){
          if(x.second > 1)
            ans.push_back(x.first);
        }
        
        return ans;
    }
};