class Solution {
public:
    int dp[502];
    int find(int st , int k , vector<int>& arr){
        
        int n = arr.size();
        if(st >= n) return 0;
        
        if(dp[st] != -1) return dp[st];

        int mxsum =0; int mx=0;
        for(int i=st ; i < st+k && i < n ; i++){
      
            mx = max(mx , arr[i]);
            int sum = find(i+1,k,arr);
            mxsum = max(mxsum , sum+mx*(i-st+1));
            // if(st==3) 
            //    cout <<st<<" "<<i<<" "<< mx<<" "<<sum<<" "<<mxsum<<endl;
        }

        return dp[st]= mxsum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       memset(dp,-1,sizeof(dp));
       return find(0,k,arr);
    }
};