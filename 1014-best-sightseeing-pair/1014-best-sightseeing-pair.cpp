class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
       
        int mxScore = 0 , mxleft = values[0]+0 , n = values.size();
        
        for(int j=1 ; j<n ; j++){
            mxScore = max(mxScore , mxleft + values[j] - j);
            mxleft = max(mxleft , values[j]+j);
        }
        
        return mxScore;
    }
};