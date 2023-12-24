class Solution {
public:
    int func(char ch , string s){
        
        int op = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]!=ch){
                op++;
            }
           ch = (ch=='0')?'1':'0';
        }
        return op;
    }
    int minOperations(string s) {
              
         int op1 = func('0',s);
         int op2 = func('1',s);
        
        return min(op1,op2);
    }
};