class Solution {
public:
    map <char,int> mp1,mp2;
    
  /*  void print(){
        for(auto x: mp1)
            cout << x.first << " " << x.second << endl;
        cout <<"mp2\n";
        for(auto x: mp2)
            cout << x.first << " " << x.second << endl;
    }*/
    
    bool closeStrings(string w1, string w2) {
        
        if(w1.size() != w2.size())
            return false;
        
      //  map <char,int> mp1 , mp2;
        
        for(auto ch : w1)
            mp1[ch]++;
        
        for(auto ch : w2)
            mp2[ch]++;
        
        if(mp1.size() != mp2.size())
            return false;
        
        auto y = mp2.begin();
        vector<int> f1,f2;
        
        for(auto x : mp1){
            if(x.first != y->first) return false;
            f1.push_back(x.second);
            f2.push_back(y->second);
            y++;
        }
        
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        
        for(int i=0 ; i < f1.size(); i++){
            if(f1[i] != f2[i]) return false;
        }
        
        return true;
    }
};