class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& pnts) {
        
        sort(pnts.begin() , pnts.end());
        
        int L = pnts[0][0] , R = pnts[0][1];
        
        int ans=0;
        
        for(int i = 1 ; i < pnts.size() ;  i++){
            
            if(pnts[i][0] <= R){
                L = max(L, pnts[i][0]);
                R = min(R , pnts[i][1]);
            }
            else{
                ans++;
               // cout << L << " " << R << endl;
                L = pnts[i][0];
                R = pnts[i][1];
            }
        }
        
        ans++;
        return ans;
    }
};