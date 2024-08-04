class Solution {
public:
    const int mod = 1e9+7;
    int rangeSum(vector<int>& a, int n, int left, int rt) {
        
        vector<int> v1;
        
        for(int i = 0 ; i < n ; i++){
            int s = 0;
            for(int j = i ; j < n ; j++){
                s += a[j];
                v1.push_back(s);
            }            
        }
        
        sort(v1.begin() , v1.end());
        
        int ans = 0;
        for(int k = left-1 ; k < rt ; k++){
            ans += v1[k];
            ans = ans % mod;
        }
        
        return ans%mod;
    }
};