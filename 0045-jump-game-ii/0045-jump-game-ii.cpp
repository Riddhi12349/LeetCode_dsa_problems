class Solution {
public:
    int jump(vector<int>& nums) {
        
        //****USING GREEDY TECHNIQUE
            
          int mxReach = 0 , curReach = 0 , jumps = 0;
        
          for(int i = 0 ; i < nums.size()-1 ; i++){
              
              mxReach = max(mxReach , i + nums[i]);
              
              if(i == curReach){
                  jumps++;
                  curReach = mxReach;
              }
          }
        
        return jumps;
    }
};