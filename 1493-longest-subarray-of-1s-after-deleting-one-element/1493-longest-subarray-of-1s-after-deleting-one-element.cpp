class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        vector<int> v1;
        int n = nums.size();
      
        int cnt = 0 , f =  0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 1){ cnt++; }
            else{ 
   
                v1.push_back(cnt);
                cnt = 0; f = 1;
            }
        }
        v1.push_back(cnt);
    // means no zero in the array    
        if(f == 0){
            return cnt-1;
        }
        
        /*
        [2 , 0 , 1]
        [0 , 3, 0 , 2, 0 ,1]
        [0,3]--[0,1,1,1]
        [3]
        [2  0 ]
        */
        int mx = 0;
        for(int i = 1 ; i < v1.size() ; i++){
            mx = max(mx , v1[i]+v1[i-1]);
        }
        
        return mx;
    }
};