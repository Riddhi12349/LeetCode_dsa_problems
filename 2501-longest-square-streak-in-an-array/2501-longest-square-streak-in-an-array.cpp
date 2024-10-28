class Solution {
public:
    pair<bool,int> isPresent(vector<int>& nums , int root , int idx){
        
        int n  = nums.size();
        int pos = lower_bound(nums.begin() , nums.begin() + idx , root) - nums.begin();
        
        if(pos < n && nums[pos] == root){
            return {true, pos};
        }
        
        return {false , -1};
    }
    
    int longestSquareStreak(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> len(n , 1);
        
        sort(nums.begin() , nums.end());
        
        for(int i = 0 ; i < n ; i++){
            
            int root = sqrt(nums[i]);
            if(root*root == nums[i]){
                
                pair<bool,int> p1 = isPresent(nums , root , i);
                
                if(p1.first == true){
                    len[i] = len[p1.second] + 1;
                }
            }
            
        }
        
        int mxlen = *max_element(len.begin() , len.end());
        
        if(mxlen== 1) return -1;
        
        return mxlen;
    }
};