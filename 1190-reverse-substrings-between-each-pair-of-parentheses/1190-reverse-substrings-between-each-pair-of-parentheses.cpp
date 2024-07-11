class Solution {
public:
    string reverseParentheses(string s) {
        // (ed(etco)el) => (edocteel)
        // (,e,d,o,c,t,e,e,l)

        stack<char> st;

        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] != ')'){
                st.push(s[i]);// st=[(,e,d,(,e,t,o,c]
            }
            else{
                
                queue<char> q; //st2 = [c,o,]
                while(!st.empty() && st.top() != '('){ q.push(st.top()); st.pop(); }
                st.pop();
                
                while(!q.empty()){
                    st.push(q.front()); q.pop();
                }
                
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top(); st.pop();
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};