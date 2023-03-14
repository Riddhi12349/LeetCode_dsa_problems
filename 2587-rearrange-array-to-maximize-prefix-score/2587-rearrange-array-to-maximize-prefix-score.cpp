class Solution {
public:
 
    int maxScore(vector<int>& nums) {
        
        sort(nums.begin() , nums.end() , greater<int>());
        vector<long> prefix; 
        long sum = 0;
        int cnt = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            if(sum > 0){ cnt++; }
        }
        
        // int cnt = 0;
        // for(int i = 0 ; i < nums.size() ; i++){
        //    if(prefix[i] > 0){ cnt++ ; }  
        // }
        
        return cnt;
    }
};