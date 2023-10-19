class Solution {
public:
    string remBs(string s){
        
        string s1 = "" ,t1 = ""; 
   //     stack<char> st; 
        int cnt = 0;

        for(int i = s.size()-1 ; i >= 0 ; i--){
          if(s[i] == '#'){
                cnt++;
            }
          else{
            if(cnt == 0){
                s1 += s[i];
            }
            else{
               cnt--;
            }
           }
        }

        reverse(s1.begin() , s1.end());
        return s1;
    }

    bool backspaceCompare(string s, string t) {
        
        string p = remBs(s);
        string q = remBs(t);

        return p==q;       
    }
};

