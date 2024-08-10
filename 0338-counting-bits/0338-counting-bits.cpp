class Solution {
public:
    int countOnes(int x){
        int cnt=0;
        while(x > 0){
            int r = x%2;
            if(r==1) cnt++;
            x = x/2;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        
        vector<int> ans(n+1);
        
        for(int i=0 ; i<=n ; i++){
            int ones = countOnes(i);
            ans[i] = ones;
        }
        
        return ans;
    }
};