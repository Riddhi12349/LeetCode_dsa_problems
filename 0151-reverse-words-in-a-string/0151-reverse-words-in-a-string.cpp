class Solution {
public:
    string reverseWords(string str) {
        string s;
        string ans;
        for(int i = 0 ; i < str.size()+1 ; i++){
            if(str[i] != ' ' && i < str.size()){
                s.push_back(str[i]);
            }
            else{
                if(s.size() != 0){
                reverse(s.begin() , s.end());
                s.push_back(' ');
                ans = ans + s;
                s.clear();
                }
            }
        }
       ans.pop_back();
        reverse(ans.begin() , ans.end());
        return ans;
    }
};