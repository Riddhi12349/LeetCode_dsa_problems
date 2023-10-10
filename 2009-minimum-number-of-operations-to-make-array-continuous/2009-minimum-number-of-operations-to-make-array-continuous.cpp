class Solution {
public: 
// len = 5 
//             i
// [8,5,9,4]=>[4,5,8,9] 
//             j
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
       
        unordered_map<int,int> mp;
        int dup = 0;
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }

        vector<int> v1;
        for(auto x : mp){
            if(x.second > 1){
                dup  += x.second-1;
            }
            v1.push_back(x.first);
        }

        sort(v1.begin() , v1.end());

        int len = v1.size(); int j = 0;
        int val_need_to_be_changed = INT_MAX;

        for(int i = 0 ; i < len ; i++){
            for( ; j < len ; ){
                if(v1[j] <= v1[i]+n-1) j++;
                else{ 
                val_need_to_be_changed  = 
                min(val_need_to_be_changed  , len - (j-i));
                break;
                }
            }
            val_need_to_be_changed  = 
                min(val_need_to_be_changed  , len - (j-i));
        }

        int ans =  val_need_to_be_changed ;
    
     return ans == INT_MAX ? dup : ans + dup;

    }
};