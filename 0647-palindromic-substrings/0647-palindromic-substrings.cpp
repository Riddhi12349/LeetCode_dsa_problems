class Solution {
public:
   // int dp[1005];

    int ispal(string t, int i , int j,vector<vector<int>>& dp){
        // while(i<=j){
        //     if(t[i]!=t[j]) return false;
        //     i++;j--;
        // }
        // return true;
        if(i>=j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = t[i]==t[j]?ispal(t,i+1,j-1,dp):0;
    }
/*    
    int find(int i,string s,string p){
        
        if(i>=s.size()){
            cout <<i <<" "<< p << endl;
            if(ispal(p) && p.size()>0) return 1;
            return 0;
        }
        
       int t=p.size();
       if(dp[i][t] !=-1) return dp[i][t];
       
       int a = find(i+1,s,p+s[i]);
       int b = find(i+1,s,p);
       
        cout <<i<<" " <<a<<" "<< b<<endl;
      // return dp[i] =(a+b);
        return dp[i][t]=(a+b);
    }
    */
    int countSubstrings(string s) {
        
       int n = s.size(); 
       vector<int> not_dp(n,0);
       vector<vector<int>> dp(n,vector<int>(n,-1));
        
        //return find(0,s,"");
       for(int i=0 ; i<n ;i++){
           for(int j=i ; j<n ; j++){
              
               if(ispal(s,i,j,dp)==1){
                   //we will memoize here -- ispal()--function
                   not_dp[i]+=1;
               }
           }
       }

       int sum = accumulate(not_dp.begin(),not_dp.end(),0);
       return sum;
    }
};