#include <stack>
class Solution {
public:
    bool isPalindrome(int x) {
       
        if(x < 0){
            return false;
        }
       
       string s = to_string(x);
       
        string p = s;
        reverse(s.begin() , s.end());
        if(s == p){
            return true;
        }
        return false;
    }
};