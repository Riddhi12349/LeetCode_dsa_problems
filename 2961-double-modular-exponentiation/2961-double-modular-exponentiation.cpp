class Solution {
public:
     long long func(int a,int b,int mod){
         int cnt=b; //2 
         long long ans=1;
         while(cnt>0){
             ans = ans*a; //2*2*2
             ans = ans%mod;
            // if(ans > 1000) return -1;
             cnt--;//0
         }
         return ans;
     }
    vector<int> getGoodIndices(vector<vector<int>>& var,int target) {
        
        int  m = var.size();
        vector<int> ans;
        
        for(int i = 0 ; i < m ; i++){
           
            int x = func(var[i][0],var[i][1],10);
           // if(x==-1) continue;
            int y = func((int)x,var[i][2],var[i][3]);
    
            if(y == target) ans.push_back(i);
        }
        
        return ans;
    }
};