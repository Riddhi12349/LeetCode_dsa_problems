class Solution {
public:
    vector<int> find(string expression){
        
        vector<int> ans;
        
        for(int i=0 ; i<expression.size() ; i++){
            
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                  
                  char operatorr = expression[i];
                
                  vector<int> left = find(expression.substr(0,i));
                  vector<int> rt = find(expression.substr(i+1));
                
                  for(auto x : left){
                      for(auto y : rt){
                          
                          if(operatorr == '+'){
                              ans.push_back(x + y);
                          }
                          else if(operatorr == '-'){
                              ans.push_back(x-y);
                          }
                          else{
                              ans.push_back(x*y);
                          }
                          
                      }
                  }  
                
              }  
        }
        
        if(ans.size()==0){
            return {stoi(expression)};
        }
        
        return ans;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        
            return find(expression);
    }
};