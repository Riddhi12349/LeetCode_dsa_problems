class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        
        /*
        vector<long long> ans;
      
        long long sum = 0;
        for(int i = 0 ; i < queries.size() ; i++){
            long long sum = 0;
            for(int j = 0 ; j < nums.size() ; j++){
                sum += abs(queries[i] - nums[j]);
            }
            ans.push_back(sum);
        }
        return ans;
        
        */
        
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
        
        vector<long long> prefixSum(n+1,0);
        prefixSum[0] = 0;
        for(int i = 0 ; i < n ; i++){
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
        
        vector<long long> ans;
        
        for(int i = 0 ; i < queries.size() ; i++){
            auto itr = upper_bound(nums.begin() , nums.end() , queries[i]);
            long long  indx = itr - nums.begin();
            long long left = (indx * queries[i]) - prefixSum[indx];
            long long right =  (prefixSum[n] - prefixSum[indx])  - ((n-indx)*queries[i]);
            ans.push_back(left + right);
        }
        
        return ans;      
        
    }
};