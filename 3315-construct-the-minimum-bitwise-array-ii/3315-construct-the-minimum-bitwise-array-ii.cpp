class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        vector<int> ans;
        
        for(auto x : nums){
            
            if(x == 2){ 
               ans.push_back(-1);
                continue;
            }
           
            for(int j = 1 ; j < 31 ; j++){
                
                int isSet = x & (1 << j);
                
                if(isSet){ continue; }
                else{ 
                   
                    int val = x ^ (1 << (j-1));
                    ans.push_back(val);
                    break;
                }
            }
            
        }
        
        
        return ans;
    }
};