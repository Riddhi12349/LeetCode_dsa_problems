class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        // first remove the strings containing only 0s
        
        vector<int> v1;
        
        for(int i = 0 ; i<bank.size() ; i++){
            
            int ones = 0;
            
            for(int j = 0 ; j < bank[i].size() ; j++)
             {   if(bank[i][j] == '1') ones++;}
            
            if(ones > 0) {v1.push_back(ones);
                         }
            
        }
         
        int ans = 0; int t= v1.size();
        
       for(int i = 0 ; i < t-1 ; i++){
            int p = v1[i]*v1[i+1];
            ans += p;
        }
        
   return ans;
    }
};