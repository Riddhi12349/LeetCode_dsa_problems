class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char> st;
        int ans = 0;
        
        for(int i = 0 ; i < s.size() ; i++){
            
            if(!st.empty() && s[i] == ')' && st.top()== '('){
                st.pop();
            }
            else{
                if(s[i] == '(') st.push(s[i]);
                else{
                    ans++;
                }
            }
        }
        
        ans += st.size();
        return ans;
    }
};