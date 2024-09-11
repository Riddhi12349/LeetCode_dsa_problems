class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int prod_mx = 1 , prod_mn = 1 ;
        int mxProd = INT_MIN , mnProd = INT_MAX;
        
        for(auto x : nums){
            
            prod_mx = prod_mx*x;
            prod_mn = prod_mn*x;
            
            mxProd = max({mxProd , prod_mx , prod_mn});
            mnProd = min({mnProd , prod_mn , prod_mx});
            
            cout << "first" << prod_mx <<  " " << prod_mn << endl;
            
            int tmp = prod_mx;
             prod_mx = max({prod_mx, prod_mn  , 1});            
             prod_mn = min({prod_mn , tmp , 1});
            
            cout << "second" << prod_mx << " " << prod_mn << endl;
            
        }
        
        
        return max(mxProd , mnProd);
    }
};