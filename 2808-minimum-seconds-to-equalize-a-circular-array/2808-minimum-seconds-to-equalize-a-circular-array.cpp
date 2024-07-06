class Solution {
public:
    int minimumSeconds(vector<int>& a) {
        
        int n = a.size();
        for(int i = 0 ; i < n ; i++){
            a.push_back(a[i]);
        }
        
        unordered_map <int,vector<int>> mp;
        
        for(int i = 0 ; i < a.size() ; i++){
            mp[a[i]].push_back(i);
        }
        
        int time = INT_MAX;
        
        for(auto x  : mp){
            
            vector<int> indxs = x.second;
            int mxtime = 0; // maxm possible b/w all adjacents to convert to a single element
            
            for(int i = 0 ; i < indxs.size()-1 ; i++){
                mxtime = max(mxtime , (indxs[i+1]-indxs[i])/2);
            }
            
            time = min(time , mxtime); // among all maximums who has minimum
        }
        
        return time;
    }
};