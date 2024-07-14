class Solution {
public: 
    vector<string> ans;
    
    void find(int i , int op , int cl , int n,string tmp){
        
        
        if(op==0 &&  cl==0){
            ans.push_back(tmp);
            return;
        }
        
        if(op > 0){
            tmp += '(';
            find(i+1 , op-1 , cl , n , tmp);
            tmp.pop_back();
        }
        
        if(op < cl){
            tmp += ')';
            find(i+1 , op , cl-1, n , tmp);
            tmp.pop_back();
        } 
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        string tmp = "";
        find(0 , n , n , n , tmp);
        return ans;
    }
};