class Solution {
public:
    vector<string> ans;
    
    void find(int i , string tmp , long long s , long long prv , string num , int tar){
        
        if(i >= num.size()){ 
            if(s == tar){
                ans.push_back(tmp);
            }
            return;
        }
        
        string t = ""; long long no = 0;
        
        for(int j = i ; j < num.size() ; j++){
            
            if(j > i && num[i] == '0') { return; }
            t += num[j];
            no = no*10 + (num[j]-'0');
            
            if(i == 0){
                find(j+1 , tmp + t , s + no , no , num, tar);
            }
            else{
          
                find(j+1 , tmp + "+" + t , s + no , no , num , tar);
                find(j+1 , tmp + "-" + t , s - no , -no , num , tar);
                find(j+1 , tmp + "*" + t , s - prv + prv*no , prv*no , num , tar);
            }
            
        }
    }
    vector<string> addOperators(string num, int tar) {
        
        find(0 , "" , 0 , 0 , num , tar);
        return ans;
    }
};