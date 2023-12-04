class Solution {
public:
    string largestGoodInteger(string num) {
        
        int ans = -1;
        
        for(int i=0 ; i<num.size()-2 ; i++){
            
            int no = (num[i]-'0')*100+(num[i+1]-'0')*10+
                (num[i+2]-'0');
            if(num[i]==num[i+1] && num[i]==num[i+2]){
                ans = max(ans, no);
            }
        }
        
        if(ans > 0)
          return to_string(ans);
        if(ans == 0)  return "000";
        return "";
    }
};