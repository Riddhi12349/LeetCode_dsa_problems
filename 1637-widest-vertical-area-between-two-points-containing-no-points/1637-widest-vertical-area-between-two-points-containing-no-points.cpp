class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        sort(points.begin() , points.end()); int mx_width = 0;
        
        for(int i = 0 ; i < points.size()-1 ;  i++){
            int w = points[i+1][0]-points[i][0];
            mx_width = max(mx_width , w);
        }
        
        return mx_width;
    }
};