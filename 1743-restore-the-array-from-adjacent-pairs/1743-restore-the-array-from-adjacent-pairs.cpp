class Solution {
public:
    
    vector<int> restoreArray(vector<vector<int>>& adj) {
        
        unordered_map<int,vector<int>> mp;      
        int n = adj.size();
  
        for(int i = 0 ; i < n ; i++){
           mp[adj[i][0]].push_back(adj[i][1]);
           mp[adj[i][1]].push_back(adj[i][0]);
        }
        
        int p = mp.size();
        vector<int> ans(p , INT_MAX );
        
        unordered_map<int,int> present;

        for(auto x : mp){
            int s = x.second.size();
            if(s == 1){
               if(ans[0] == INT_MAX){
                    ans[0] = x.first;
                    vector<int> v = x.second;
                    ans[1] = v[0];
               }
               else{
                    ans[p-1] = x.first;
                    vector<int> v = x.second;
                    ans[p-2] = v[0];
               }
               present[x.first]++;
            }
            
        }
        
        int i = 1 ; 
        while(i < n-1){
            vector<int> v = mp[ans[i]];
            int a = v[0] , b = v[1];
            i++;
            if(present.count(a) == 0)
               ans[i] = a;
            if(present.count(b) == 0)
               ans[i] = b;
              
              present[ans[i-1]]++;
        }

        return ans;
    }
};