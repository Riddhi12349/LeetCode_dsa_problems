class Solution {
public:
    int subarraySum(vector<int>& a , int k) {
        
   //     A = [1,2,3,4,3,4,2,1,2,4,2,4,2]
   //   PRE = [1,3,6,10,13,17,19,20,22,26,28,32,34] k=6
        
        unordered_map<int,int> mp;
            
        int sum = 0 , ans = 0 ;
        mp[0]=1;
        
        for(int  i = 0 ; i < a.size() ; i++){
            
            sum += a[i];//a+b=k , a=k-b
            
            if(mp.count(sum-k) > 0){
                ans += mp[sum-k];
            }
            
            mp[sum]++;
        }
        
       return ans;
      
    }
};