class Solution {
public:
    int passThePillow(int n, int time) {
        
        int rem = time % (2*n-2);
        
        vector<int> v1;
        for(int i = 1 ; i <= n ; i++){ v1.push_back(i); }
        for(int i=n-1 ; i>= 0 ; i--){  v1.push_back(i); }        
        
        return v1[rem];
       
    }
};