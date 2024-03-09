class Solution {
public:
    static bool cmp(string p , string q){
        if(p.size()==q.size()) return p < q;
        return p.size()<q.size();
    }
    
    string minimumString(string a, string b, string c) {
        
        vector<vector<string>> v;
        
        v.push_back({a,b,c});
        v.push_back({a,c,b});
        v.push_back({b,c,a});
        v.push_back({b,a,c});
        v.push_back({c,a,b});
        v.push_back({c,b,a});
               
        vector<string> tb;
       
      for(auto v1 : v){ 
        
          string ans = v1[0];
          
        for(int i = 1; i < 3 ; i++){
            
            int tmp1 = -1 , tmp2 = -1;
            string s2 = v1[i];
            
            if(ans.find(s2) != string::npos){
                continue;
            }
            for(int k = ans.size()-1; k >= 0 ; k--){
               
                if(ans[k]==s2[0]){
                    int len = ans.size()-k;
                    string p = s2.substr(0 , len);
                    string q = ans.substr(k);
                    if(p==q){ tmp1 = k; tmp2 = len; }
                }
            }
            
            if(tmp1 != -1 && tmp2 != -1){
                string t = s2.substr(tmp2); ans = ans+t;
             }
            else{
                ans=ans+s2;
            }
        }
          
          tb.push_back(ans);
      }
        sort(tb.begin() , tb.end() , cmp);
        for(auto x : tb){cout << x << " ";} cout << endl;
        return tb[0];
         
    }
};