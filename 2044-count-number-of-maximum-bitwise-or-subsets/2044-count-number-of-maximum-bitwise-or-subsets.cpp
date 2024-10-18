class Solution {
public:
    int find(int i , int orr , int MaxOrr ,
             vector<int>& a , vector<int>& v1){
        
        int n = a.size();
        
        if(i >= n){
            if(orr == MaxOrr) return 1;
            return 0;
        }
      
        int x_take = find(i+1 ,  orr | a[i] , MaxOrr, a , v1);
       
        int y_nottake = find(i+1 , orr,  MaxOrr , a, v1);
        
        return x_take + y_nottake;
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        
        int orr = 0;
        for(auto x : nums){
            orr = orr | x;
        }
        
       vector<int> v1;
       int cnt =  find(0, 0, orr , nums , v1);
       
       return cnt;
    }
};