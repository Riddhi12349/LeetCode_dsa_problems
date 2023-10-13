class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        stack<char> st; unordered_map<char,int> mp;
        
        for(int i = 0 ; i < s.size() ; i++){
            mp[s[i]]++;
        }
        
       
        unordered_map<char,int> mp_charInSt;
        
        for(int i = 0 ; i < s.size() ; i++){
           
            while(!st.empty() && 
         mp_charInSt.count(s[i]) == 0 && s[i] < st.top() && 
                 mp[st.top()] > 0){
                
                 mp_charInSt.erase(st.top());
                 st.pop();
            }
            
            if(mp_charInSt.count(s[i])==0){
              st.push(s[i]); 
              mp_charInSt[s[i]]++;   
            }
            
            mp[s[i]]--;
        }
        
        string ans = "";
        
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            ans += ch;
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};