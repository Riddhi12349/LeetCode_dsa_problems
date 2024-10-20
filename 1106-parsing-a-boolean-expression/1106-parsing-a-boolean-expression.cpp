class Solution {
public:
    bool parseBoolExpr(string expr) {
        
        stack<char> st_Operator , st2_expr;
        
  for(int j = 0 ; j < expr.size() ; j++){
            
   if(expr[j] == '&' || expr[j] == '|' || expr[j] == '!'){
        st_Operator.push(expr[j]);
    }
   else{
       if(expr[j] != ')'){
          
           if(expr[j] == 'f'){ st2_expr.push('0'); }
           else if(expr[j] == 't'){ st2_expr.push('1'); }
           else if(expr[j] == '('){ st2_expr.push('(');  }
       }
       else{
           char operatorr = st_Operator.top();
           st_Operator.pop();
           
           int val;
           
           if(operatorr == '|'){
               
               val = 0;
               while(!st2_expr.empty() && st2_expr.top() != '('){
                   val = val | (st2_expr.top()-'0');
                   st2_expr.pop();
               }
               
               st2_expr.pop();
               
           }
           else if(operatorr == '&'){
               
               val = 1;
               while(!st2_expr.empty() && st2_expr.top() != '('){
                   val = val & (st2_expr.top()-'0');
                   st2_expr.pop();
               }
               
               st2_expr.pop();   
           }
           else{
               
               val = (st2_expr.top()-'0');
               st2_expr.pop();
               st2_expr.pop();
               
               val = !val;
           }
           
           
           if(val == 0) st2_expr.push('0');
           else st2_expr.push('1');
       }
   }
 
  }
        
        if(st2_expr.top() == '0') return false;
        else return true;
        
    }
};