class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        
        vector<int> ans; stack<int> st; 
        
        int n = ast.size();
        
        for(int i = 0 ; i < n ; i++){
            
            while(!st.empty() && st.top() > 0 && ast[i] < 0 &&
                 abs(ast[i]) > st.top() ){ 
                            st.pop();
            }
            
            if(!st.empty()){
                
                if(st.top() > 0 && ast[i] < 0){
                    if(abs(ast[i]) == st.top()){ st.pop(); continue; }
                    else if(abs(ast[i]) < st.top()) { continue; }
                }
            }
            
            st.push(ast[i]);
        }
        
        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }
        
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};