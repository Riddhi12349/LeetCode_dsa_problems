class Solution {
public:
    int jump(vector<int>& nums) {
        
        //****USING GREEDY TECHNIQUE
         int n= nums.size();
         int jumps = 0 , l = 0  , r = 0 ;
        
         while(r < n-1){
             
               int farthest = INT_MIN;
             
               for(int i = l ; i <= r; i++){
                   farthest = max(farthest , i + nums[i]);
               }
             
               l = r+1;
               r = farthest;
               jumps++;
         }
        
         return jumps;
    }
};