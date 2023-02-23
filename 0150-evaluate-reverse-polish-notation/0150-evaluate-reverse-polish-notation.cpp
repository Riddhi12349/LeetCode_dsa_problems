class Solution {
public:
 #include <string>
    int evalRPN(vector<string>& tokens) {
      
        stack<int> st;
      
  for(int i = 0 ; i < tokens.size() ; i++){
     if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
        string str = tokens[i];
         int x = stoi(str);
         st.push(x);
     }
     else{
         int a = st.top();
         st.pop();
         int b = st.top();
         st.pop();
         int ans ;
         if(tokens[i] == "+"){
             ans = b + a;
         }
         else if(tokens[i] == "-"){
             ans = b-a;
         }
         else if(tokens[i] == "*"){
             ans = b*a;
         }
         else{
             ans = b/a;
         }
         st.push(ans);
     }
        }
        return st.top();
    }
};