class Solution {
public:
    void print(vector<string>& v1){
        for(auto x : v1)
           cout << x << " ";
        cout << endl;
    }
    vector<string> findHighAccessEmployees(
        vector<vector<string>>& at) {

       vector<string> ans;
       unordered_map <string,vector<string>> mp;

       for(int i=0 ; i < at.size() ; i++){
           mp[at[i][0]].push_back(at[i][1]);
       } 

       for(auto x : mp){
           
           vector<string> v2 = x.second;
           sort(v2.begin(),v2.end());

           for(int i=0 ; i < v2.size() ; i++){
             
             string s = v2[i];
             string p = to_string(stoi(s.substr(0,2))+1);
            
             string t ="";
             if(p.size()==1) t += '0';
            
              t += p + s.substr(2);
             
            int pos = lower_bound(v2.begin() , v2.end() , t)-v2.begin();

            if(pos-1 >= 0 && v2[pos-1]< t){
                if(pos-i >= 3)
                  { cout << t << endl;
                    ans.push_back(x.first);
                   ///cout << pos<<" " <<i << endl;
                  // print(v2);
                   break; }
            }

           }
       }

       return ans;
    }
};