class Solution {
public:
    static bool cmp(vector<int>& v1 , vector<int>& v2){
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin() , intervals.end() , cmp);
        
        int n = intervals.size() , ans = 0;
        
        int l = intervals[0][0] , r = intervals[0][1];
        
        for(int i = 1 ;  i < n ; i++){
            
            if(intervals[i][0] >= r){
                l = intervals[i][0];
                r = intervals[i][1];
            }
            else{
                ans++;
            }   
        }
        
        return ans;
    }
};