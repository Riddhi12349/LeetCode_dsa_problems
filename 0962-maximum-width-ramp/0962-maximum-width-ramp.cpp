class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<pair<int,int>> v1;
        
        for(int i = 0 ; i < n ; i++){
            v1.push_back({nums[i] , i});
        }
        
        sort(v1.begin() , v1.end());
        
        int mxW = 0;
        
        int mnIndx = v1[0].second;
        
        for(int i = 1 ; i < n ; i++){
            
            if(mnIndx < v1[i].second){
                mxW = max(mxW , v1[i].second - mnIndx);
            }
            
            mnIndx = min(mnIndx , v1[i].second);
        }
        
        return mxW;
    }
};