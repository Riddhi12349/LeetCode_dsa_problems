class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        unordered_map <int,int> mp;
        
        int r=-1, m=-1;
        
        for(auto x : nums){
            mp[x]++;
            if(mp[x]>=2) r=x;
        }
       
        for(int i=1 ; i<= nums.size() ; i++){
            if(mp.count(i)==0) m=i;
        }
        
        return {r,m};
    }
};