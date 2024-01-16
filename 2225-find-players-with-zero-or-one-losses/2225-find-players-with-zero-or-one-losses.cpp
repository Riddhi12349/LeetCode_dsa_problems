class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        vector<vector<int>> ans(2); int mx=0;
        unordered_map <int,int> mp_l,mp_w;
        
        for(int i = 0 ; i < matches.size() ; i++){
            mp_l[matches[i][1]]++;
            mp_w[matches[i][0]]++;
        }
        
        for(auto x : mp_l){
            if(x.second == 1){
                ans[1].push_back(x.first);
            }
        }
        sort(ans[1].begin() , ans[1].end());
       
        for(auto x : mp_w){
            if(mp_l.count(x.first)==0)
                ans[0].push_back(x.first);
        }
        sort(ans[0].begin() , ans[0].end());
        
        return ans;
    }
};