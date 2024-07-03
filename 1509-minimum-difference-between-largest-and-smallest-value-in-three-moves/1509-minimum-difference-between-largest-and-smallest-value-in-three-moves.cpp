class Solution {
public:
    int minDifference(vector<int>& a) {
       // [0,1,1,4,6,6,6]
        int n = a.size();
        
        if(n <= 4) return 0;
        
        sort(a.begin() , a.end());
        
        //case-1 : shuru se 3
        int d1 = a[n-1]-a[3];
        
        //case-2 : shuru se 2 and last 1
        int d2 = a[n-2]-a[2];
        
        //case-3 : shuru se 1 and last 2
        int d3 = a[n-3]-a[1];
        
        //case-4 : last se 3
        int d4 = a[n-4]-a[0];
        
        return min(d1 , min({d2,d3,d4}));
    }
};