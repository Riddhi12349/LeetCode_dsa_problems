class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        unordered_map <int,int> mp;
        
        for(auto i : nums)
            mp[i]++;
      
        int ans = 0;
        
        for(auto x : mp){
            int t = x.second;
            if(t==1) return -1;
            
            if(t % 3 == 0) ans += (t/3);
            else if(t % 3 == 1) ans += (((t/3)-1)+2);// t=5/3=1
            else  ans += ((t/3)+1); 
           
        }
        
        return ans;
    }
};