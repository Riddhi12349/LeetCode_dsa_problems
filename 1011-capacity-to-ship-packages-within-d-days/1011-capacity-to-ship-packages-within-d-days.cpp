class Solution {
public:
    
    bool isPossible(vector<int>& wts , int mid , int gdays){
        int d = 1 , s = 0;
        for(int i = 0 ; i < wts.size() ; i++){
            s += wts[i];
            if(s > mid){
                d += 1;
                s = wts[i];
            }
        }
        return d <= gdays;
    }

    int shipWithinDays(vector<int>& wts, int days) {
        int Max = 0 , sum = 0;
        for(int i = 0 ; i < wts.size() ; i++){
            sum += wts[i];
            Max = max(Max , wts[i]);
        }
    if(days == 1){ return sum; }
    if(days == wts.size()) { return Max; }
        int lo = Max , hi = sum , mid ,ans = 0;
         while(lo <= hi){
             mid = (lo + hi)/2;
             if(isPossible(wts , mid , days)){
                 ans = mid;
                 hi = mid - 1;
             }
             else{
                 lo = mid + 1;
             }
         }
         return ans;
    }
};