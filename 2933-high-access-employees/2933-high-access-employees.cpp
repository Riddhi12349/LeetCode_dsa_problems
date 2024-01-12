class Solution {
public:
    vector<string> findHighAccessEmployees(
        vector<vector<string>>& at) {
        
        unordered_map <string,vector<string>> mp;
        
        for(int i=0 ; i < at.size() ; i++){
            mp[at[i][0]].push_back(at[i][1]);
        }
        
        vector<string> ans;
        
        for(auto x : mp){
            
            vector<string> v1 = x.second;
            sort(v1.begin() , v1.end());
            
           for(int i=0 ; i < v1.size() ; i++){
            
               string tmp = v1[i].substr(0,2);
               string a = to_string(stoi(tmp)+1);
               string s="";
               if(a.size()<2) {s="0";}
               
               string p  = s+a+v1[i].substr(2);
                 cout<<p<<endl;
               int pos = lower_bound(v1.begin(),v1.end(),p)-v1.begin();
              cout<<x.first << " " << pos<<endl;
               if((v1[pos-1] < p) && (pos-i>=3)){
                   ans.push_back(x.first);
                   break;
               }
               }
        }
        
        return ans;
    }
};