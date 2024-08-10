class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int> open, star; // store indicesof open brackets and stars
        
        for(int i=0 ; i < s.size() ; i++){
            
            if(s[i] == '('){
                open.push(i);
            }
            else if(s[i] == '*'){
                star.push(i);
            }
            else if(s[i] == ')'){
                
                if(!open.empty()) open.pop();
                
                else if(!star.empty()) star.pop();
                
                else return false;
            }
        }
        
        while(!open.empty() && !star.empty() && open.top() < star.top()){
            //"(*"
            star.pop();
            open.pop();
        }
        
        if(!open.empty()) return false;
        
        return true;
    }
};