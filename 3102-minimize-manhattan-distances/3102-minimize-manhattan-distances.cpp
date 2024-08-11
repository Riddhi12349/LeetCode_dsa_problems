class Solution {
public:
    vector<int> findMaxMnD(vector<vector<int>>& pnts, int idx){
        
        vector<int> mxSum = {-1 , INT_MIN} , mnSum = {-1 , INT_MAX};
        vector<int> mnDiff = {-1, INT_MAX}  , mxDiff = {-1 , INT_MIN};
        
        for(int i = 0 ; i < pnts.size() ; i++){
             
            if(i == idx) { continue; }
            
                int sum = pnts[i][0] + pnts[i][1];
                int diff = pnts[i][0] - pnts[i][1];
            
             if(mxSum[1] < sum){
                 mxSum[1] = sum; mxSum[0] = i;
             }
             if(mnSum[1] > sum){
                 mnSum[1] = sum; mnSum[0] = i;
             }
             if(mnDiff[1] > diff){
                 mnDiff[1] = diff; mnDiff[0] = i;
             }
             if(mxDiff[1] < diff){
                 mxDiff[1] = diff; mxDiff[0] = i;
             }
            
        }
        
        int d1 = mxSum[1]-mnSum[1];
        int d2 = mxDiff[1]-mnDiff[1];
        
        if(d1 > d2){
            return {d1 , mxSum[0] , mnSum[0]};                         
        }
        
        return {d2 , mxDiff[0] , mnDiff[0]};
        
    }
    
    int minimumDistance(vector<vector<int>>& pnts) {
        
     vector<int> v1 = findMaxMnD(pnts , -1);
        
     int i = v1[1] , j = v1[2];
       
     return min( findMaxMnD(pnts , i)[0] , findMaxMnD(pnts , j)[0] );
          
    }
};