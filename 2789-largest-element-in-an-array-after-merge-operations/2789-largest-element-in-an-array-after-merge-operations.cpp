class Solution {
public:
    long long maxArrayValue(vector<int>& a) {
        
        long long sum = 0 , mxsum = 0;
        int n = a.size();
        
        for(int i = n-1 ; i >= 0 ; i--){
            sum += a[i];
            if(i-1 >= 0 &&  sum < a[i-1]){ 
                   mxsum = max(mxsum , sum);
                   sum = 0;
            }
        }
        
        return max(mxsum , sum);
    }
};